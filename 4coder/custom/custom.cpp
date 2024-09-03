/*
 - Supplies the default bindings used for default 4coder behavior.
*/

// TOP

#if !defined(FCODER_DEFAULT_BINDINGS_CPP)
#define FCODER_DEFAULT_BINDINGS_CPP

#include "4coder_default_include.cpp"

// NOTE(allen): Users can declare their own managed IDs here.
#include "4coder_language_ids.cpp"
#include "4coder_terickson_ids.cpp"

#include "generated/managed_id_metadata.cpp"

global Arena tc_global_arena = {};
global b32 tc_debug_toggle = true;

struct FunctionPreviewContext
{
  Arena arena;
  Temp_Memory temp_mem;
  bool open;
  
  View_ID view;
  
  u64 active_function_hash;
  String_Const_u8 function_name;
  List_String_Const_u8 params;
};
FunctionPreviewContext g_function_preview;

function FunctionPreviewContext*
get_function_preview_context()
{
  return &g_function_preview;
}

#include "4coder_terickson_helper.cpp"

#include "4coder_terickson_language.cpp"

// Extensions
#include "ext/4coder_terickson_function_index.cpp"
#if 0
#include "ext/4coder_terickson_std_include.cpp"
#endif
#include "ext/4coder_terickson_todo.cpp"

// Languages
#include "languages/cpp/cpp.cpp"
#include "languages/odin/odin.cpp"
#include "languages/glsl/glsl.cpp"
#include "languages/gas/gas.cpp"
#include "languages/nasm/nasm.cpp"

// Miscellaneous
#include "4coder_terickson_prjlib.cpp"
#include "4coder_terickson_error_message.cpp"
#include "4coder_terickson_scopeline.cpp"
#include "4coder_terickson_highlight.cpp"
#include "4coder_terickson_hooks.cpp"
#include "4coder_terickson_lists.cpp"
#include "4coder_terickson_commands.cpp"

#include "mb.cpp"
#include "mb_bindings.cpp"
#include "mb_hooks.cpp"
#include "mb_function_list.cpp"


void
custom_layer_init(Application_Links *app)
{
  Thread_Context *tctx = get_thread_context(app);
  tc_global_arena = make_arena_system();
  get_function_preview_context()->arena = make_arena_system();
  
  // NOTE(allen): setup for default framework
  default_framework_init(app);
  code_index_init();
  
  // NOTE: Custom
  mb_init(app);
  
  // Multi-Language Support
  init_ext_language();
  
  // Language Dependent Extensions
  //init_ext_std_include();
  init_ext_todo();
    
    // Language Definitions
	init_language_cpp();
	init_language_odin();
	init_language_glsl();
	init_language_gas();
	init_language_nasm();
    
    // Some Processing on Language Definitions
  finalize_languages(app);
  
  // NOTE(allen): default hooks and command maps
  set_all_default_hooks(app);
  set_language_hooks(app);
  set_custom_hook(app, HookID_WholeScreenRenderCaller, tc_whole_screen_render_caller);

  // NOTE: Custom
  set_custom_hook(app, HookID_Tick, mb_tick);
  set_custom_hook(app, HookID_ViewEventHandler, mb_view_input_handler);
  set_custom_hook(app, HookID_RenderCaller, mb_render_caller);

  
  mapping_init(tctx, &framework_mapping);
  String_ID global_map_id = vars_save_string_lit("keys_global");
  String_ID file_map_id = vars_save_string_lit("keys_file");
  String_ID code_map_id = vars_save_string_lit("keys_code");
#if OS_MAC
  setup_mac_mapping(&framework_mapping, global_map_id, file_map_id, code_map_id);
#else
  setup_default_mapping(&framework_mapping, global_map_id, file_map_id, code_map_id);
#endif
	setup_essential_mapping(&framework_mapping, global_map_id, file_map_id, code_map_id);

  mb_set_bindings(app);
}

function void
function_preview_reset(Application_Links* app)
{
  FunctionPreviewContext* ctx = get_function_preview_context();
  if (ctx->temp_mem.temp_memory_arena.arena)
  {
    end_temp(ctx->temp_mem);
  }
  ctx->temp_mem = begin_temp(&ctx->arena);
}

function void
push_function_signature_from_token(Application_Links* app, Buffer_ID buffer, Token token)
{
  Scratch_Block scratch(app);

  Language *language = *buffer_get_language(app, buffer);
  Extension_Support *ext_support = language_get_extension(language, EXT_FUNCTION_INDEX);
  Language_Function_Indexer *lang_indexer;
 
  if (!ext_support)
  {
    return;
  }
  
  lang_indexer = (Language_Function_Indexer *)ext_support->ext_interface.str;  
  
  //Token_Array token_array = get_token_array_from_buffer(app, buffer);
  //i64 token_index = token_index_from_pos(&token_array, cursor);
  
  //if (token_array.tokens[token_index].kind == TokenBaseKind_Identifier)
  {
    FunctionPreviewContext* ctx = get_function_preview_context();
    //Token token = token_array.tokens[token_index];
    Function_Index_List indices = function_indices_from_token(app, scratch, buffer, token, lang_indexer);
    Function_Index *index = indices.first;
    
    if (index)
    {
      function_preview_reset(app);
      ctx->params = lang_indexer->parameter_strings(index, &ctx->arena);
      ctx->function_name = push_token_lexeme(app, &ctx->arena, buffer, &token);
      ctx->open = true;
    }
  }
}

function String_Const_u8
get_function_signature_string(Arena* arena)
{
  FunctionPreviewContext* ctx = get_function_preview_context();
  
  String_u8 string = string_u8_push(arena, ctx->params.total_size + ctx->function_name.size + ctx->params.node_count*3);
 
  string_append(&string, ctx->function_name);  
  string_append(&string, string_u8_litexpr("("));
  
  for (Node_String_Const_u8* node = ctx->params.first;
       node != 0;
       node = node->next)
  {
    string_append(&string, node->string);
    if (node->next != 0)
    {
      string_append(&string, string_u8_litexpr(", "));
    }
  }
  string_append(&string, string_u8_litexpr(")"));
  
  return string.string;
}

function void
function_preview_render(Application_Links* app, Buffer_ID buffer, View_ID view, Text_Layout_ID text_layout_id)
{
  FunctionPreviewContext* ctx = get_function_preview_context();
  if (!ctx->open)
  {
    return;
  }
  
  Scratch_Block scratch(app);
  
  Face_ID face_id = mb_get_small_font_face();
  Face_Metrics metrics = get_face_metrics(app, face_id);
  Rect_f32 view_rect = view_get_screen_rect(app, view);
    
  i64 cursor_pos = view_get_cursor_pos(app, view);
  i64 line = get_line_number_from_pos(app, buffer, cursor_pos);
  line -= 1;
  Range_i64 line_range = get_line_pos_range(app, buffer, line);
    
  Rect_f32 rect = text_layout_character_on_screen(app, text_layout_id, line_range.min);
    
  ARGB_Color color = finalize_color(defcolor_back, 0);
  
  String_Const_u8 string = get_function_signature_string(scratch);
  
  f32 string_width = get_string_advance(app, face_id, string);
  //f32 view_width = rect_width(view_rect);
  
  rect.x1 += string_width;
  draw_rectangle(app, rect, 0, color);
  draw_margin(app, rect, rect_inner(rect, 1), finalize_color(defcolor_text_default, 0));

  /* Draw parameter highlight */
  if (ctx->params.node_count > 0)
  {
    Code_Index_File* code_index = code_index_get_file(buffer);
    if (!code_index)
    {
      return;
    }
    
    Code_Index_Nest* nest = code_index_get_nest(code_index, cursor_pos);
    Token_Array token_array = get_token_array_from_buffer(app, buffer);
    i64 token_index = token_index_from_pos(&token_array, nest->open.min);      i64 param_index = 0;
    
    i32 paren_nest = 0;
    
    Assert(token_array.tokens[token_index].pos <= cursor_pos);
    
    while (true)
    {
      token_index++;
      Token token = token_array.tokens[token_index];
      
      if (token.pos > cursor_pos)
      {
        break;
      }
      
      if (token.kind == TokenBaseKind_ParentheticalOpen)
      {
        paren_nest += 1;
      }
      else if (token.kind == TokenBaseKind_ParentheticalClose)
      {
        paren_nest -= 1;
      }
      else if (token.kind == TokenBaseKind_StatementClose &&
               paren_nest == 0)
      {
        String_Const_u8 token_str = push_token_lexeme(app, scratch, buffer, &token);
        if (string_match(token_str, string_u8_litexpr(",")))
        {
          param_index += 1;
        }
      }
    }
    
    //print_message(app, push_u8_stringf(scratch, "param index - %i\n", param_index));
    // Get parameter offset and size
    f32 advance = 0;
    advance += get_string_advance(app, face_id, ctx->function_name);
    advance += get_string_advance(app, face_id, string_u8_litexpr("("));
    int i = 0;
    Node_String_Const_u8 *node = ctx->params.first;
    for (;node != 0; node = node->next)
    {
      if (i >= param_index)
      {
        break;
      }
      advance += get_string_advance(app, face_id, node->string);
      if (i < ctx->params.node_count-1)
      {
        advance += get_string_advance(app, face_id, string_u8_litexpr(", "));
      }
      i += 1;
    }
    
    if (node != 0)
    {
      String_Const_u8 curr_param_string = node->string;
      f32 param_width = get_string_advance(app, face_id, curr_param_string);
      
      Rect_f32 highlight_rect = {
        rect.x0+advance, rect.y0,
        rect.x0+advance+param_width, rect.y1,
      };
      
      draw_rectangle(app, highlight_rect, 0, finalize_color(defcolor_highlight_white, 0));
    }
  }
  
  Vec2_f32 draw_pos =
  {
    rect.x0,
    rect.y0,
  };
  color = finalize_color(defcolor_text_default, 0);
    
  draw_pos = draw_string(app, face_id, string, draw_pos, color);
}

function void
function_preview_tick(Application_Links* app)
{
  Scratch_Block scratch(app);
  
  View_ID view = get_active_view(app, Access_Always);
  Buffer_ID buffer =  view_get_buffer(app, view, Access_Read);
  i64 cursor_pos = view_get_cursor_pos(app, view);
  FunctionPreviewContext* ctx = get_function_preview_context();
  
  Code_Index_File* code_index = code_index_get_file(buffer);
  
  if (!code_index)
  {
    return;
  }
  
  Code_Index_Nest* nest = code_index_get_nest(code_index, cursor_pos);
  
  if (!nest) 
  {
    ctx->active_function_hash = max_u64;
    ctx->open = false;
    return;
  }
 
  if (nest->kind == CodeIndexNest_Paren)
  {
    Token_Array token_array = get_token_array_from_buffer(app, buffer);
    i64 token_index = token_index_from_pos(&token_array, nest->open.min);      token_index--;
    
    while (token_index > 0 &&
           token_array.tokens[token_index].kind == TokenBaseKind_Whitespace)
    {
      token_index--;
    }
    
    if (token_index >= 0)
    {
      Token token = token_array.tokens[token_index];
      String_Const_u8 token_name =  push_token_lexeme(app, scratch, buffer, &token);
      u64 hash = hash_crc64(token_name.str, token_name.size);
      if (ctx->active_function_hash != hash)
      {
        ctx->active_function_hash = hash;
        push_function_signature_from_token(app, buffer, token);
      }
    }
  }
  else
  {
    ctx->active_function_hash = max_u64;
    ctx->open = false;
  }
}

#endif //FCODER_DEFAULT_BINDINGS

// BOTTOM

