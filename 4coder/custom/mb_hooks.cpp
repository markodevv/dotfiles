function void function_preview_tick(Application_Links* app);

function void
mb_tick(Application_Links* app, Frame_Info frame_info)
{
  ////////////////////////////////
  // NOTE(allen): Update code index
  
  language_code_index_update_tick(app);
  language_run_hooks(Tick, app, frame_info);
  function_preview_tick(app);
  
  if (tick_all_fade_ranges(app, frame_info.animation_dt))
  {
    animate_in_n_milliseconds(app, 0);
  }
}

CUSTOM_COMMAND_SIG(mb_view_input_handler)
CUSTOM_DOC("Input consumption loop for default view behavior")
{
  Scratch_Block scratch(app);
  default_input_handler_init(app, scratch);
  
  View_ID view = get_this_ctx_view(app, Access_Always);
  Managed_Scope scope = view_get_managed_scope(app, view);
  
  for (;;)
  {
    // NOTE(allen): Get input
    User_Input input = get_next_input(app, EventPropertyGroup_Any, 0);
    if (input.abort)
    {
      break;
    }
    
    ProfileScopeNamed(app, "before view input", view_input_profile);
    
    // NOTE(allen): Mouse Suppression
    Event_Property event_properties = get_event_properties(&input.event);
    if((suppressing_mouse && (event_properties & EventPropertyGroup_AnyMouseEvent) != 0))
    {
      continue;
    }
    
    if(mb_handle_input(app, &input.event))
    {
      continue;
    }
    
    // NOTE(allen): Get binding
    if(implicit_map_function == 0)
    {
      implicit_map_function = default_implicit_map;
    }
    Implicit_Map_Result map_result = implicit_map_function(app, 0, 0, &input.event);
    if(map_result.command == 0)
    {
      leave_current_input_unhandled(app);
      continue;
    }
    
    /*
    if(!(event_properties & EventPropertyGroup_AnyMouseEvent) && input.event.kind != InputEventKind_None)
    {
      vim_keystroke_text.size = 0;
    }
    */
    
    // NOTE(allen): Run the command and pre/post command stuff
    default_pre_command(app, scope);
    ProfileCloseNow(view_input_profile);
    
    map_result.command(app);
    
    ProfileScope(app, "after view input");
    default_post_command(app, scope);
  }
}

function void
function_preview_render(Application_Links* app, Buffer_ID buffer, View_ID view, Text_Layout_ID text_layout_id);

static void mb_render_buffer(Application_Links *app, View_ID view_id, Face_ID face_id,
                             Buffer_ID buffer, Text_Layout_ID text_layout_id,
                             Rect_f32 rect)
{
  ProfileScope(app, "[TErickson] render buffer");
  
  View_ID active_view = get_active_view(app, Access_Always);
  b32 is_active_view = active_view == view_id;
  Rect_f32 prev_clip = draw_set_clip(app, rect);
  
  // NOTE(allen): Cursor shape
  Face_Metrics metrics = get_face_metrics(app, face_id);
  f32 cursor_roundness = (metrics.normal_advance*0.5f)*0.9f;
  f32 mark_thickness = 2.f;
  
  // Language **language = buffer_get_language(app, buffer);
  Token_Array token_array = get_token_array_from_buffer(app, buffer);
  if (token_array.tokens != 0)
  {
    language_paint_tokens(app, buffer, text_layout_id, &token_array);
    b32 use_comment_keyword = def_get_config_b32(vars_save_string_lit("use_comment_keyword"));
    if (use_comment_keyword)
      tc_paint_comment_keywords(app, buffer, text_layout_id, &token_array);
  }
  else
  {
    Range_i64 visible_range = text_layout_get_visible_range(app, text_layout_id);
    paint_text_color_fcolor(app, text_layout_id, visible_range, fcolor_id(defcolor_text_default));
  }
  
  i64 cursor_pos = view_correct_cursor(app, view_id);
  view_correct_mark(app, view_id);
  
  // NOTE(allen): Scope highlight
  b32 use_scope_highlight = def_get_config_b32(vars_save_string_lit("use_scope_highlight"));
  if (use_scope_highlight){
    Color_Array colors = finalize_color_array(defcolor_back_cycle);
    draw_scope_highlight(app, buffer, text_layout_id, cursor_pos, colors.vals, colors.count);
  }
  
  b32 use_error_highlight = def_get_config_b32(vars_save_string_lit("use_error_highlight"));
  b32 use_jump_highlight = def_get_config_b32(vars_save_string_lit("use_jump_highlight"));
  if (use_error_highlight || use_jump_highlight){
    // NOTE(allen): Error highlight
    String_Const_u8 name = string_u8_litexpr("*compilation*");
    Buffer_ID compilation_buffer = get_buffer_by_name(app, name, Access_Always);
    if (use_error_highlight){
      draw_jump_highlights(app, buffer, text_layout_id, compilation_buffer,
                           fcolor_id(defcolor_highlight_junk));
      tc_render_error_messages(app, buffer, compilation_buffer, active_view, text_layout_id);
    }
    
    // NOTE(allen): Search highlight
    if (use_jump_highlight){
      Buffer_ID jump_buffer = get_locked_jump_buffer(app);
      if (jump_buffer != compilation_buffer){
        draw_jump_highlights(app, buffer, text_layout_id, jump_buffer,
                             fcolor_id(defcolor_highlight_white));
      }
    }
  }
  
  if (is_active_view)
    tc_render_scopeline(app, buffer, active_view, text_layout_id);
  
  
  // NOTE(allen): Color parens
  b32 use_paren_helper = def_get_config_b32(vars_save_string_lit("use_paren_helper"));
  if (use_paren_helper){
    Color_Array colors = finalize_color_array(defcolor_text_cycle);
    draw_paren_highlight(app, buffer, text_layout_id, cursor_pos, colors.vals, colors.count);
  }
  
  // NOTE(allen): Line highlight
  b32 highlight_line_at_cursor = def_get_config_b32(vars_save_string_lit("highlight_line_at_cursor"));
  if (highlight_line_at_cursor && is_active_view){
    i64 line_number = get_line_number_from_pos(app, buffer, cursor_pos);
    draw_line_highlight(app, text_layout_id, line_number,
                        fcolor_id(defcolor_highlight_cursor_line));
  }
 
  if (is_active_view)
  {
    mb_highlight_range(app, view_id, text_layout_id);
  }
  
  // NOTE(allen): Whitespace highlight
  b64 show_whitespace = false;
  view_get_setting(app, view_id, ViewSetting_ShowWhitespace, &show_whitespace);
  if (show_whitespace){
    if (token_array.tokens == 0){
      draw_whitespace_highlight(app, buffer, text_layout_id, cursor_roundness);
    }
    else{
      draw_whitespace_highlight(app, text_layout_id, &token_array, cursor_roundness);
    }
  }
  
  // NOTE(allen): Cursor
  switch (fcoder_mode){
    case FCoderMode_Original:
    {
      mb_draw_cursor(app, view_id, is_active_view, buffer, text_layout_id, cursor_roundness, mark_thickness);
    } break;
    case FCoderMode_NotepadLike:
    {
      draw_notepad_style_cursor_highlight(app, view_id, buffer, text_layout_id, cursor_roundness);
    } break;
  }
  
  // NOTE(allen): Fade ranges
  paint_fade_ranges(app, text_layout_id, buffer);
  
  // NOTE(allen): put the actual text on the actual screen
  draw_text_layout_default(app, text_layout_id);
  
  if (is_active_view && g_state.mode == Editor_Insert)
  {
    function_preview_render(app, buffer, view_id, text_layout_id);
  }

  draw_set_clip(app, prev_clip);
}

function void mb_render_caller(Application_Links *app, Frame_Info frame_info, View_ID view_id){
  ProfileScope(app, "[TErickson] render caller");
  View_ID active_view = get_active_view(app, Access_Always);
  b32 is_active_view = (active_view == view_id);
  
  Rect_f32 region = draw_background_and_margin(app, view_id, is_active_view);
  Rect_f32 prev_clip = draw_set_clip(app, region);
  
  Buffer_ID buffer = view_get_buffer(app, view_id, Access_Always);
  Face_ID face_id = get_face_id(app, buffer);
  Face_Metrics face_metrics = get_face_metrics(app, face_id);
  f32 line_height = face_metrics.line_height;
  f32 digit_advance = face_metrics.decimal_digit_advance;
  
  // NOTE(allen): file bar
  b64 showing_file_bar = false;
  if (view_get_setting(app, view_id, ViewSetting_ShowFileBar, &showing_file_bar) && showing_file_bar){
    Rect_f32_Pair pair = layout_file_bar_on_top(region, line_height);
    draw_file_bar(app, view_id, buffer, face_id, pair.min);
    region = pair.max;
  }
  
  Buffer_Scroll scroll = view_get_buffer_scroll(app, view_id);
  
  Buffer_Point_Delta_Result delta = delta_apply(app, view_id,
                                                frame_info.animation_dt, scroll);
  if (!block_match_struct(&scroll.position, &delta.point)){
    block_copy_struct(&scroll.position, &delta.point);
    view_set_buffer_scroll(app, view_id, scroll, SetBufferScroll_NoCursorChange);
  }
  if (delta.still_animating){
    animate_in_n_milliseconds(app, 0);
  }
  
  // NOTE(allen): query bars
  region = default_draw_query_bars(app, region, view_id, face_id);
  
  // NOTE(allen): FPS hud
  if (show_fps_hud){
    Rect_f32_Pair pair = layout_fps_hud_on_bottom(region, line_height);
    draw_fps_hud(app, frame_info, face_id, pair.max);
    region = pair.min;
    animate_in_n_milliseconds(app, 1000);
  }
  
  // NOTE(allen): layout line numbers
  Rect_f32 line_number_rect = {};
  b32 show_line_number_margins = def_get_config_b32(vars_save_string_lit("show_line_number_margins"));
  if (show_line_number_margins){
    Rect_f32_Pair pair = layout_line_number_margin(app, buffer, region, digit_advance);
    line_number_rect = pair.min;
    region = pair.max;
  }
  
  // NOTE(allen): begin buffer render
  Buffer_Point buffer_point = scroll.position;
  Text_Layout_ID text_layout_id = text_layout_create(app, buffer, region, buffer_point);
  
  // NOTE(allen): draw line numbers
  if (show_line_number_margins){
    draw_line_number_margin(app, view_id, buffer, face_id, text_layout_id, line_number_rect);
  }
  
  mb_render_buffer(app, view_id, face_id, buffer, text_layout_id, region);
  
  text_layout_free(app, text_layout_id);
  draw_set_clip(app, prev_clip);
}


