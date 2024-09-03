function Buffer_ID
get_or_create_jumplist_buffer(Application_Links* app, bool clear = true)
{
  String_Const_u8 name = string_u8_litexpr("*jumplist*");
  Buffer_ID buffer = get_buffer_by_name(app, name, Access_Always);

  if (!buffer_exists(app, buffer))
  {
    buffer = create_buffer(app, name, BufferCreate_AlwaysNew);
    buffer_set_setting(app, buffer, BufferSetting_Unimportant, true);
    buffer_set_setting(app, buffer, BufferSetting_ReadOnly, true);
  }
  else
  {
    if (clear)
    {
      clear_buffer(app, buffer);
    }
    buffer_send_end_signal(app, buffer);
  }

  return buffer;
}

function i64 
get_functions_positions_from_buffer(Application_Links *app, Buffer_ID buffer, Function_Positions *positions_array, i64 positions_max)
{
  Code_Index_File* file = code_index_get_file(buffer);
  if (file == 0)
  {
    return 0;
  }

  Token_Array token_array = get_token_array_from_buffer(app, buffer);
  i64 positions_count = 0;

  for (i32 i = 0; i < file->note_array.count; i++)
  {
    Code_Index_Note *note = file->note_array.ptrs[i];

    if (note->note_kind == CodeIndexNote_Function)
    {
      // String_Const_u8 str = push_u8_stringf(scratch, "%.*s\n", string_expand(note->text));
      // print_message(app, str);
      Token_Iterator_Array it = token_iterator_pos(0, &token_array, note->pos.min);

      Function_Positions positions = {};

      positions.sig_start_index = token_it_index(&it);
      i32 paren_nest = 0;

      for (;;)
      {
        if (!token_it_inc(&it))
        {
          break;
        }

        Token *token = token_it_read(&it);

        if (token->kind == TokenBaseKind_ParentheticalOpen)
        {
          if (positions.open_paren_pos == 0)
          {
            positions.open_paren_pos = token->pos;
          }
          paren_nest += 1;
        }

        if (token->kind == TokenBaseKind_ParentheticalClose)
        {
          paren_nest -= 1;
          if (paren_nest == 0)
          {
            positions.sig_end_index = token_it_index(&it);
            positions_array[positions_count++] = positions;
            break;
          }
        }
      }

      if (positions_count >= positions_max)
      {
        // print_positions_buffered(app, &out, buffer, positions_array, positions_count);
        break;
      }
      // String_Const_u8 token_string = push_token_lexeme(app, scratch, buffer, token);
      // print_message(app, push_u8_stringf(scratch, "%.*s\n", string_expand(token_string)));
    }
  }

  return positions_count;
}

function void
print_functions_to_jumplist(Application_Links *app, Buffer_ID target_buffer = 0)
{
  Buffer_ID jumplist_buffer = get_or_create_jumplist_buffer(app);

  Scratch_Block scratch(app);

  i32 positions_max = KB(4)/sizeof(Function_Positions);
  Function_Positions *positions_array = push_array(scratch, Function_Positions, positions_max);

  Cursor insertion_cursor = make_cursor(push_array(scratch, u8, KB(256)), KB(256));
  Buffer_Insertion out = begin_buffer_insertion_at_buffered(app, jumplist_buffer, 0, &insertion_cursor);

  for (Buffer_ID buffer_it = get_buffer_next(app, 0, Access_Always);
       buffer_it != 0;
       buffer_it = get_buffer_next(app, buffer_it, Access_Always))
  {
    if (target_buffer != 0)
    {
      buffer_it = target_buffer;
    }

    i64 positions_count = get_functions_positions_from_buffer(app, buffer_it, positions_array, positions_max);
    if (positions_count > 0)
    {
      print_positions_buffered(app, &out, buffer_it, positions_array, positions_count);
    }

    if (target_buffer != 0)
    {
      break;
    }
  }

  end_buffer_insertion(&out);
}

CUSTOM_UI_COMMAND_SIG(list_functions_all_buffers)
CUSTOM_DOC("..")
{
  View_ID view = get_active_view(app, Access_ReadVisible);
  print_functions_to_jumplist(app);

  Buffer_ID jumplist_buffer = get_or_create_jumplist_buffer(app, false);

  view_set_buffer(app, view, jumplist_buffer, 0);
  footer_panel_set_buffer(app, jumplist_buffer);
  lock_jump_buffer(app, string_u8_litexpr("*jumplist*"));

  Heap *heap = &global_heap;
  Marker_List *list = get_or_make_list_for_buffer(app, heap, jumplist_buffer);
  if (list != 0){
      Jump_Lister_Result jump = get_jump_index_from_user(app, list, "Function:");
      jump_to_jump_lister_result(app, view, list, &jump);
  }
}

CUSTOM_UI_COMMAND_SIG(list_functions_in_buffer)
CUSTOM_DOC("..")
{
  View_ID view = get_active_view(app, Access_ReadVisible);
  Buffer_ID buffer = view_get_buffer(app, view, Access_ReadVisible);

  print_functions_to_jumplist(app, buffer);

  Buffer_ID jumplist_buffer = get_or_create_jumplist_buffer(app, false);
  footer_panel_set_buffer(app, jumplist_buffer);
  lock_jump_buffer(app, string_u8_litexpr("*jumplist*"));

  Heap *heap = &global_heap;
  Marker_List *list = get_or_make_list_for_buffer(app, heap, jumplist_buffer);
  if (list != 0){
      Jump_Lister_Result jump = get_jump_index_from_user(app, list, "Function:");
      jump_to_jump_lister_result(app, view, list, &jump);
  }
}

