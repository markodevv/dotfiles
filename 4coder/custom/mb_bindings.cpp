function void map_set_binding(u32 mode, void *func, u64 key)
{
  if((mode & bitmask_3) == 0)
  {
    mode |= bitmask_3;
/*
    foreach(s,VIM_SUBMODE_COUNT)
    { 
      map_set_binding(mode, s, func, key);
    }
*/
  }
  if(mode & bit_1)
  {
    table_insert(g_state.maps + 0, key, PtrAsInt(func)); 
  }
  if(mode & bit_2)
  { 
    table_insert(g_state.maps + 1, key, PtrAsInt(func)); 
  }
  if(mode & bit_3)
  { 
    table_insert(g_state.maps + 2, key, PtrAsInt(func)); 
  }
}

function void VimBind(u32 mode, Custom_Command_Function *custom, u64 key)
{
  map_set_binding(mode, (void *)custom, key);
}

function void mb_goto_mark(Application_Links *app)
{
  View_ID view = get_active_view(app, Access_ReadVisible);
  i64 pos = view_get_mark_pos(app, view);
  view_set_cursor_and_preferred_x(app, view, seek_pos(pos));
}

function void mb_set_bindings(Application_Links *app)
{
#define N bit_1
#define I bit_2
#define V bit_3
#define MAP 0
  u32 Ctl = KeyMod_Ctl;
  u32 Sft = KeyMod_Sft;
  u32 Alt = KeyMod_Alt;

  VimBind(N|MAP, insert_mode,                   KeyCode_I);
  VimBind(N|MAP, move_down,                         KeyCode_J);
  VimBind(N|MAP, move_up,                           KeyCode_K);
  VimBind(N|MAP, move_left,                         KeyCode_H);
  VimBind(N|MAP, move_right,                        KeyCode_L);
  VimBind(N|MAP, goto_end_of_file,                  (Sft|KeyCode_G));
  VimBind(N|MAP, goto_line,                         (Sft|KeyCode_Semicolon));
  VimBind(N|MAP, mb_goto_scope,                     (Sft|KeyCode_5));
  VimBind(N|MAP, mb_auto_indent_scope,              (Sft|KeyCode_Equal));
  VimBind(N|MAP, quick_swap_buffer,                 (Ctl|KeyCode_N));
  VimBind(N|MAP, set_mark,                          KeyCode_M);
  VimBind(N|MAP, mb_goto_mark,                      (Sft|KeyCode_M));
  VimBind(N|MAP, undo,                              KeyCode_U);
  VimBind(N|MAP, redo,                              (Sft|KeyCode_R));
  VimBind(N|MAP, newline_bellow,                KeyCode_O);
  VimBind(N|MAP, page_up,                           (Alt|KeyCode_K));
  VimBind(N|MAP, page_down,                         (Alt|KeyCode_J));
  VimBind(N|MAP, move_right_whitespace_or_token_boundary, KeyCode_W);
  VimBind(N|MAP, move_left_whitespace_or_token_boundary,  KeyCode_B);
  VimBind(N|MAP, change_active_panel,               (Alt|KeyCode_W));
  VimBind(N|MAP, search,                            KeyCode_ForwardSlash);
  VimBind(N|MAP, visual_mode,                       KeyCode_V);
  VimBind(N|MAP, mb_build,                          (Alt|KeyCode_M));
  VimBind(N|MAP, interactive_open_or_new,           (Alt|KeyCode_F));
  VimBind(N|MAP, save,                              (Alt|KeyCode_S));
  VimBind(N|MAP, mb_goto_next_jump,                    (Alt|KeyCode_E));
  VimBind(N|MAP, mb_goto_prev_jump,                    (Alt|KeyCode_Q));
  VimBind(N|MAP, comment_line_toggle,               (Ctl|KeyCode_C));
  VimBind(N|MAP, mb_toggle_footer_panel,            KeyCode_Tick);
  VimBind(N|MAP, line_start_insert,             (Sft|KeyCode_I));
  VimBind(N|MAP, line_end_insert,               (Sft|KeyCode_A));
  VimBind(N|MAP, insert_after_char,             KeyCode_A);
  VimBind(N|MAP, mb_delete_char,                    KeyCode_X);
  VimBind(N|MAP, copy,                              KeyCode_Y);
  VimBind(N|MAP, paste,                             KeyCode_P);
  VimBind(N|MAP, paste_and_indent,                  (Sft|KeyCode_P));
  VimBind(N|MAP, cut_til_line_end,              (Sft|KeyCode_C));
  VimBind(N|MAP, jump_to_definition_at_cursor,              (Ctl|KeyCode_W));
  VimBind(N|MAP, list_functions_in_buffer,     (Alt|KeyCode_P));
  VimBind(N|MAP, list_functions_all_buffers,   (Alt|Sft|KeyCode_P));
  VimBind(N|MAP, language_goto_jump_at_cursor, (Sft|KeyCode_Return));
  VimBind(N|MAP, language_comment_line_toggle, (Ctl|KeyCode_C));
  VimBind(N|MAP, seek_next_search,          KeyCode_N);
  VimBind(N|MAP, seek_prev_search,         (Sft|KeyCode_N));
  VimBind(N|MAP, mb_list_all_locations_query,  KeyCode_F3);
  VimBind(N|MAP, mb_list_all_locations_of_identifier,  (Ctl|KeyCode_F));

  VimBind(V|MAP, v_delete_range,                KeyCode_D);
  VimBind(V|MAP, v_cut_range,                   KeyCode_C);
  VimBind(V|MAP, v_copy,                        KeyCode_Y);
  VimBind(V|MAP, normal_mode,                   KeyCode_Escape);
  VimBind(V|MAP, move_down,                         KeyCode_J);
  VimBind(V|MAP, move_up,                           KeyCode_K);
  VimBind(V|MAP, move_left,                         KeyCode_H);
  VimBind(V|MAP, move_right,                        KeyCode_L);
  VimBind(V|MAP, move_right_whitespace_or_token_boundary, KeyCode_W);
  VimBind(V|MAP, move_left_whitespace_or_token_boundary,  KeyCode_B);
  VimBind(V|MAP, replace_in_range,                  KeyCode_S);
  VimBind(V|MAP, language_comment_range, (Ctl|KeyCode_C));
  VimBind(V|MAP, mb_list_all_locations_from_selection,  (Ctl|KeyCode_F));

  VimBind(I|MAP, normal_mode,                   KeyCode_Escape);
}


