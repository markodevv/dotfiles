#pragma once

#define foreach(i,N) for(i32 i=0; i<N; i++)
#define ArrayInc(a,i) ((i+1) % ArrayCount(a))
#define ArrayDec(a,i) ((i + ArrayCount(a)-1) % ArrayCount(a))
#define printf_message(app, arena, str, ...) print_message(app, push_stringf(arena, str, __VA_ARGS__))

enum EditorMode
{
  Editor_Normal,
  Editor_Insert,
  Editor_Visual,
  Editor_MODE_COUNT,
  // These modes just have hard-coded behavior
  Editor_Visual_Insert,
  Editor_Replace,
};

/*
enum VimSubMode
{
  SUB_None,
  SUB_G,
  SUB_Z,
  SUB_Leader,
  //SUB_Window,
  VIM_SUBMODE_COUNT,
};
*/

struct EditorState
{
  EditorMode mode;
  History_Group history_group;

  Table_u64_u64 maps[Editor_MODE_COUNT];
  
  Face_ID small_font_face;
};

global_const u32 KeyMod_Ctl = bit_32;
global_const u32 KeyMod_Sft = bit_31;
global_const u32 KeyMod_Alt = bit_30;
global_const u32 KeyMod_Cmd = bit_29;
global_const u32 KeyMod_Mnu = bit_28;
