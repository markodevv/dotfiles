#include "mb.h"

global EditorState g_state;

function Buffer_ID
get_or_create_jumplist_buffer(Application_Links* app, bool clear);

function void
mb_init(Application_Links *app)
{
  g_state.mode = Editor_Normal;
  
  Base_Allocator *base = get_base_allocator_system();
  
  foreach(i, ArrayCount(g_state.maps))
  {
    g_state.maps[i] = make_table_u64_u64(base, 100);
  }
  
  Scratch_Block scratch(app);
  
  Face_Description normal_code_desc = get_face_description(app, get_face_id(app, 0));
  
  Face_Description desc = {};
  {
    desc.font.file_name = def_search_normal_full_path(scratch, str8_lit("fonts/Inconsolata-Regular.ttf"));

    desc.parameters.pt_size = normal_code_desc.parameters.pt_size - 1;
    desc.parameters.bold = 1;
    desc.parameters.italic = 1;
    desc.parameters.hinting = 0;
  }
  
  g_state.small_font_face = try_create_new_face(app, &desc);
  //get_or_create_jumplist_buffer(app, true);
}

function Face_ID
mb_get_small_font_face()
{
  return g_state.small_font_face;
}

function void insert_mode(Application_Links *app)
{
	View_ID view = get_active_view(app, Access_ReadVisible);
	Buffer_ID buffer = view_get_buffer(app, view, Access_ReadVisible);
  g_state.history_group = history_group_begin(app, buffer);
  g_state.mode = Editor_Insert;
}

function void normal_mode(Application_Links *app)
{
  if (g_state.mode == Editor_Insert)
  {
    history_group_end(g_state.history_group);
  }
  g_state.mode = Editor_Normal;
}

CUSTOM_COMMAND_SIG(visual_mode)
{
  if (g_state.mode != Editor_Visual)
  {
    set_mark(app);
    g_state.mode = Editor_Visual;
  }
  else
  {
    normal_mode(app);
  }
}

function b32
mb_handle_input(Application_Links *app, Input_Event *event)
{
  if (event->kind == InputEventKind_KeyStroke)
  {
    Key_Code key = event->key.code;

    if (key != KeyCode_Control && key != KeyCode_Shift && 
        key != KeyCode_Alt && key != KeyCode_Command && 
        key != KeyCode_Menu)
    {
      foreach(i, event->key.modifiers.count)
      {
        Key_Code mod = event->key.modifiers.mods[i];
        if(0){}
        else if(mod == KeyCode_Control){ key |= KeyMod_Ctl; }
        else if(mod == KeyCode_Shift){   key |= KeyMod_Sft; }
        else if(mod == KeyCode_Alt){     key |= KeyMod_Alt; }
        else if(mod == KeyCode_Command){ key |= KeyMod_Cmd; }
        else if(mod == KeyCode_Menu){    key |= KeyMod_Mnu; }
      }
    }

    u64 function_data;
    if (table_read(g_state.maps + g_state.mode, key, &function_data))
    {
      Custom_Command_Function *vim_func = (Custom_Command_Function *)IntAsPtr(function_data);
      if (vim_func)
      {
        View_ID view = get_active_view(app, Access_ReadVisible);
        Managed_Scope scope = view_get_managed_scope(app, view);

        default_pre_command(app, scope);
        vim_func(app);
        default_post_command(app, scope);
        return true;
      }
    }
    else
    {
      if (g_state.mode != Editor_Insert)
      {
        String_ID map_id = vars_save_string_lit("keys_global");
        Command_Binding command_binding = map_get_binding_non_recursive(&framework_mapping, map_id, event);

        if(command_binding.custom)
        {
          command_binding.custom(app);
        }

        return true;
      }
    }
  }
  return false;
}

function void
mb_highlight_range(Application_Links* app, View_ID view, Text_Layout_ID text_layout_id)
{
  if (g_state.mode == Editor_Visual)
  {
    i64 mark_pos = view_get_mark_pos(app, view);
    i64 cursor_pos = view_get_cursor_pos(app, view);
    //i64 token_index = token_index_from_pos(array, mark_pos);
    draw_character_block(app, text_layout_id, Ii64(mark_pos, cursor_pos), 0, fcolor_id(defcolor_highlight_white));
  }
}

function void
mb_draw_cursor(Application_Links *app, View_ID view_id, b32 is_active_view,
                                                 Buffer_ID buffer, Text_Layout_ID text_layout_id,
                                                 f32 roundness, f32 outline_thickness){
    b32 has_highlight_range = draw_highlight_range(app, view_id, buffer, text_layout_id, roundness);

    Managed_ID cursor_color;

    if (g_state.mode == Editor_Normal)
    {
      cursor_color = defcolor_cursor;
    }
    else if (g_state.mode == Editor_Insert)
    {
      cursor_color = defcolor_special_character;
    }
    else
    {
      cursor_color = 0xFF00FFFF;
    }

    if (!has_highlight_range){
        i32 cursor_sub_id = default_cursor_sub_id();
        
        i64 cursor_pos = view_get_cursor_pos(app, view_id);
        i64 mark_pos = view_get_mark_pos(app, view_id);
        if (is_active_view){
            draw_character_block(app, text_layout_id, cursor_pos, roundness,
                                 fcolor_id(cursor_color, cursor_sub_id));
            paint_text_color_pos(app, text_layout_id, cursor_pos,
                                 fcolor_id(defcolor_at_cursor));
            draw_character_wire_frame(app, text_layout_id, mark_pos,
                                      roundness, outline_thickness,
                                      fcolor_id(defcolor_mark));
        }
        else{
            draw_character_wire_frame(app, text_layout_id, mark_pos,
                                      roundness, outline_thickness,
                                      fcolor_id(defcolor_mark));
            draw_character_wire_frame(app, text_layout_id, cursor_pos,
                                      roundness, outline_thickness,
                                      fcolor_id(cursor_color, cursor_sub_id));
        }
    }
}

CUSTOM_COMMAND_SIG(end_line)
{
  // Vim_Motion_Block vim_motion_block(app);

  View_ID view = get_active_view(app, Access_ReadVisible);
  Buffer_ID buffer = view_get_buffer(app, view, Access_ReadVisible);
  i64 pos = view_get_cursor_pos(app, view);
  i64 new_pos = get_line_side_pos_from_pos(app, buffer, pos, Side_Max);
  // if(vim_state.params.request == REQUEST_Change)
  {
    new_pos -= (buffer_get_char(app, buffer, new_pos) == '\n');
    new_pos -= (buffer_get_char(app, buffer, new_pos) == '\r');
  }
  view_set_cursor_and_preferred_x(app, view, seek_pos(new_pos));
}

CUSTOM_COMMAND_SIG(newline_bellow)
{
  end_line(app);
  View_ID view = get_active_view(app, Access_ReadVisible);
  Buffer_ID buffer = view_get_buffer(app, view, Access_ReadVisible);

  History_Group history_group = history_group_begin(app, buffer);

  i64 line = get_line_number_from_pos(app, buffer, view_get_cursor_pos(app, view));
  if (!line_is_valid_and_blank(app, buffer, line))
  {
    move_right(app);
  }
  // history_group_end(history_group);
  insert_mode(app);

  write_text(app, string_u8_litexpr("\n"));
  auto_indent_line_at_cursor(app);

}

CUSTOM_COMMAND_SIG(toggle_build_panel)
{
  Buffer_ID buffer = get_comp_buffer(app);
  if (buffer != 0)
  {
    View_ID view = get_first_view_with_buffer(app, buffer);
    if (view == 0)
    {
      view = get_active_view(app, Access_Always);
      View_ID footer_view_id = open_footer_panel(app, view);
      view_set_buffer(app, footer_view_id, buffer, 0);
    }
    else
    {
      view_close(app, view);
    }
  }
}

function void v_delete_range(Application_Links *app)
{
  // move_right(app);
  delete_range(app);
  normal_mode(app);
}

function void yank_delete_range(Application_Links* app)
{
  copy(app);
  delete_range(app);
}

function void v_cut_range(Application_Links *app)
{
  insert_mode(app);
  // move_right(app);
  yank_delete_range(app);
}

function void v_copy(Application_Links *app)
{
  copy(app);
  normal_mode(app);
}

function void line_end_insert(Application_Links *app)
{
  seek_pos_of_textual_line(app, Side_Max);
  insert_mode(app);
}

function void insert_after_char(Application_Links *app)
{
  move_right(app);
  insert_mode(app);
}

function void line_start_insert(Application_Links *app)
{
  seek_pos_of_textual_line(app, Side_Min);
  insert_mode(app);
}

function void cut_til_line_end(Application_Links *app)
{
  set_mark(app);
  seek_pos_of_textual_line(app, Side_Max);
  yank_delete_range(app);
  insert_mode(app);
}

function void mb_delete_char(Application_Links *app)
{
  View_ID view = get_active_view(app, Access_ReadWriteVisible);
  Buffer_ID buffer = view_get_buffer(app, view, Access_ReadWriteVisible);
  i64 pos = view_get_cursor_pos(app, view);
  i64 end = pos + 1;
  // i64 buffer_size = buffer_get_size(app, buffer);
  buffer_replace_range(app, buffer, Ii64(pos, end), string_u8_empty);
}

function void mb_goto_scope(Application_Links* app)
{
  View_ID view = get_active_view(app, Access_Always);
  Buffer_ID buffer = view_get_buffer(app, view, Access_Read);
  
  Code_Index_File *index = code_index_get_file(buffer);
  if (!index) return;
  
  i64 cursor_pos = view_get_cursor_pos(app, view);
  i64 nest_find_pos = cursor_pos;

  char c;
  buffer_read_range(app, buffer, Ii64(cursor_pos, cursor_pos+1), (u8*)&c);
 
  if (c == '(' || c == '{')
  {
    nest_find_pos += 1;
  }
  
  Code_Index_Nest *nest = code_index_get_nest(index, nest_find_pos);
  if (!nest) 
  {
    return;
  }

    
  if (cursor_pos == nest->open.min)
  {
    view_set_cursor_and_preferred_x(app, view, seek_pos(nest->close.min));
  }
  else if (cursor_pos == nest->close.min)
  {
    view_set_cursor_and_preferred_x(app, view, seek_pos(nest->open.min));
  }
  else
  {
    view_set_cursor_and_preferred_x(app, view, seek_pos(nest->open.min));
  }
}

function void mb_auto_indent_scope(Application_Links* app)
{
  View_ID view = get_active_view(app, Access_Always);
  Buffer_ID buffer = view_get_buffer(app, view, Access_Read);
  
  Code_Index_File *index = code_index_get_file(buffer);
  if (!index) return;
  
  i64 cursor_pos = view_get_cursor_pos(app, view);
  
  Code_Index_Nest *nest = code_index_get_nest(index, cursor_pos);
  if (!nest) 
  {
    return;
  }
  
  auto_indent_buffer(app, buffer, Ii64(nest->open.max, nest->close.min));
}

CUSTOM_COMMAND_SIG(seek_next_search)
CUSTOM_DOC("Test")
{
  View_ID view = get_active_view(app, Access_Always);
  Buffer_ID buffer = view_get_buffer(app, view, Access_Read);
  i64 cursor_pos = view_get_cursor_pos(app, view);
  i64 new_pos = 0;
  i64 buffer_size = buffer_get_size(app, buffer);
  
  String_Const_u8 string;
  string.str = (u8*)&previous_isearch_query[0];
  string.size = cstring_length(previous_isearch_query);
    
  seek_string_forward(app, buffer, cursor_pos, 0, string, &new_pos);
  
  if (new_pos < buffer_size)
  {
    view_set_cursor_and_preferred_x(app, view, seek_pos(new_pos)); 
  }
}

CUSTOM_COMMAND_SIG(seek_prev_search)
CUSTOM_DOC("Test")
{
  View_ID view = get_active_view(app, Access_Always);
  Buffer_ID buffer = view_get_buffer(app, view, Access_Read);
  i64 cursor_pos = view_get_cursor_pos(app, view);
  i64 new_pos = 0;
  //i64 buffer_size = buffer_get_size(app, buffer);
  
  String_Const_u8 string;
  string.str = (u8*)&previous_isearch_query[0];
  string.size = cstring_length(previous_isearch_query);
    
  seek_string_backward(app, buffer, cursor_pos, 0, string, &new_pos);
  
  if (new_pos > 0)
  {
    view_set_cursor_and_preferred_x(app, view, seek_pos(new_pos)); 
  }
}

global View_ID g_footer_view_id;
global Buffer_ID g_last_footer_buffer_id;

function void
mb_close_footer_panel(Application_Links* app)
{
  if (view_exists(app, g_footer_view_id))
  {
    g_last_footer_buffer_id = view_get_buffer(app, g_footer_view_id, Access_Always);
    view_close(app, g_footer_view_id);
  }
  g_footer_view_id = 0;
}

function View_ID
mb_open_footer_panel(Application_Links* app, Buffer_ID buffer = 0)
{  
  if (!view_exists(app, g_footer_view_id))
  {
    Panel_ID root = panel_get_root(app);
    
    panel_split(app, root, Dimension_Y);
    Panel_ID new_panel_id = panel_get_child(app, root, Side_Max);
    
    View_ID new_view_id = panel_get_view(app, new_panel_id,
                                         Access_Always);
    view_set_passive(app, new_view_id, true);
    view_set_buffer(app, new_view_id, buffer, 0);
    
    Face_ID face_id = get_face_id(app, buffer);
    Face_Metrics metrics = get_face_metrics(app, face_id);
    view_set_split_pixel_size(app, new_view_id, (i32)(metrics.line_height*12.f));    
    
    g_footer_view_id = new_view_id;
  }
  
  return g_footer_view_id;
}

function void
footer_panel_set_buffer(Application_Links* app, Buffer_ID buffer)
{
  g_last_footer_buffer_id = buffer;
  if (view_exists(app, g_footer_view_id))
  {
    view_set_buffer(app, g_footer_view_id, buffer, 0);
  }
}

CUSTOM_COMMAND_SIG(mb_toggle_footer_panel)
CUSTOM_DOC("...")
{
  if (!view_exists(app, g_footer_view_id))
  {
    mb_open_footer_panel(app, g_last_footer_buffer_id);
  }
  else
  {
    mb_close_footer_panel(app);
  }
}

CUSTOM_COMMAND_SIG(mb_build)
CUSTOM_DOC("...")
{
  View_ID view = get_active_view(app, Access_Always);
  Buffer_ID buffer = view_get_buffer(app, view, Access_Always);
 
  Buffer_ID comp_buffer = get_comp_buffer(app);
  
  View_ID footer_view = mb_open_footer_panel(app, comp_buffer);
  standard_search_and_build(app, footer_view, buffer);
  set_fancy_compilation_buffer_font(app);
  
  block_zero_struct(&prev_location);
  lock_jump_buffer(app, string_u8_litexpr("*compilation*"));
}

internal void
mb_list_all_locations(Application_Links *app, String_Const_u8_Array name, List_All_Locations_Flag flags){
  if (name.count > 0)
  {
    Buffer_ID jumplist_buffer = get_or_create_jumplist_buffer(app, true);
    mb_open_footer_panel(app, jumplist_buffer);
    
    String_Match_Flag must_have_flags = 0;
    String_Match_Flag must_not_have_flags = 0;
    
    if (HasFlag(flags, ListAllLocationsFlag_CaseSensitive))
    {
      AddFlag(must_have_flags, StringMatch_CaseSensitive);
    }
    
    if (!HasFlag(flags, ListAllLocationsFlag_MatchSubstring))
    {
      AddFlag(must_not_have_flags, StringMatch_LeftSideSloppy);
      AddFlag(must_not_have_flags, StringMatch_RightSideSloppy);
    }
    
    print_all_matches_all_buffers(app, name, must_have_flags, must_not_have_flags, jumplist_buffer);
  }
}

CUSTOM_COMMAND_SIG(mb_list_all_locations_query)
CUSTOM_DOC("...")
{
  Scratch_Block scratch(app);
  u8 *space = push_array(scratch, u8, KB(1));
  String_Const_u8 needle = get_query_string(app, "List Locations For: ", space, KB(1));
  String_Const_u8_Array array = {&needle, 1};
  mb_list_all_locations(app, array, ListAllLocationsFlag_CaseSensitive|ListAllLocationsFlag_MatchSubstring);
  block_zero_struct(&prev_location);
  lock_jump_buffer(app, string_u8_litexpr("*jumplist*"));
}

CUSTOM_COMMAND_SIG(mb_list_all_locations_from_selection)
CUSTOM_DOC("...")
{
  Scratch_Block scratch(app);
  String_Const_u8 needle = push_view_range_string(app, scratch);
  String_Const_u8_Array array = {&needle, 1};
  mb_list_all_locations(app, array, ListAllLocationsFlag_CaseSensitive|ListAllLocationsFlag_MatchSubstring);
  lock_jump_buffer(app, string_u8_litexpr("*jumplist*"));
  normal_mode(app);
}

CUSTOM_COMMAND_SIG(mb_list_all_locations_of_identifier)
CUSTOM_DOC("...")
{
  Scratch_Block scratch(app);
  String_Const_u8 needle = push_token_or_word_under_active_cursor(app, scratch);
  String_Const_u8_Array array = {&needle, 1};
  mb_list_all_locations(app, array, ListAllLocationsFlag_CaseSensitive);
  block_zero_struct(&prev_location);
  lock_jump_buffer(app, string_u8_litexpr("*jumplist*"));
}

function Locked_Jump_State
mb_get_locked_jump_state(Application_Links* app, Heap* heap)
{
  Locked_Jump_State result = {};
  result.view = get_view_for_locked_jump_buffer(app);
  if (result.view != 0)
  {
    Buffer_ID buffer = view_get_buffer(app, result.view, Access_Always);
    result.list = language_get_or_make_list_for_buffer(app, heap, buffer);
    
    i64 cursor_position = view_get_cursor_pos(app, result.view);
    Buffer_Cursor cursor = buffer_compute_cursor(app, buffer, seek_pos(cursor_position));
    result.list_index = get_index_nearest_from_list(app, result.list, cursor.line);
  }
  return(result);
  
}
  
CUSTOM_COMMAND_SIG(mb_goto_next_jump)
CUSTOM_DOC("If a buffer containing jump locations has been locked in, goes to the next jump in the buffer, skipping sub jump locations.")
{
  Heap *heap = &global_heap;
  
  Locked_Jump_State jump_state = mb_get_locked_jump_state(app, heap);
  if (jump_state.view != 0)
  {
    i64 cursor_position = view_get_cursor_pos(app, jump_state.view);
    Buffer_Cursor cursor = view_compute_cursor(app, jump_state.view, seek_pos(cursor_position));
    i64 line = get_line_from_list(app, jump_state.list, jump_state.list_index);
    if (line <= cursor.line)
    {
      jump_state.list_index += 1;
    }
    goto_next_filtered_jump(app, jump_state.list, jump_state.view, jump_state.list_index, 1, true, true);
  }
}


CUSTOM_COMMAND_SIG(mb_goto_prev_jump)
CUSTOM_DOC("If a buffer containing jump locations has been locked in, goes to the previous jump in the buffer, skipping sub jump locations."){
  Heap *heap = &global_heap;
  
  Locked_Jump_State jump_state = mb_get_locked_jump_state(app, heap);
  if (jump_state.view != 0)
  {
    if (jump_state.list_index > 0)
    {
      --jump_state.list_index;
    }
    goto_next_filtered_jump(app, jump_state.list, jump_state.view, jump_state.list_index, -1, true, true);
  }
  
}
CUSTOM_COMMAND_SIG(mb_jump_to_definition_at_cursor)
CUSTOM_DOC("...")
{
  View_ID view = get_active_view(app, Access_Visible);
  
  if (view != 0)
  {
    Scratch_Block scratch(app);
    String_Const_u8 token_name = push_token_or_word_under_active_cursor(app, scratch);
    code_index_lock();
   
    Buffer_ID buffer_id = view_get_buffer(app, view, Access_Read);
    Language *language = *buffer_get_language(app, buffer_id);
    
    if (language)
    {
      Code_Index_Table *index_table = &language->master_code_index;
      Code_Index_Note_List **list_ref = index_map_get(&index_table->notes, hash_crc64(token_name.str, token_name.size));
      if (list_ref && (*list_ref)->first)
      {
        Code_Index_Note_List *list = *list_ref;
        for (Code_Index_Note *note = list->first; 
             note; 
             note = note->next)
        {
          if (string_match(token_name, note->text))
          {
            point_stack_push_view_cursor(app, view);
            jump_to_location(app, view, note->file->buffer, note->pos.first);
            break;
          }
        }
      }
      
    }

    code_index_unlock();
  }
}
