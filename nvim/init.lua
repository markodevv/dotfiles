require("lsp_settings")

local os = vim.loop.os_uname().sysname;
local run_command = "..\\build\\game.exe" 
local build_command = "py build.py"
local config_file

if os == "Windows_NT" then
  config_file = "~/AppData/Local/nvim/init.lua<CR>"
  --vim.api.nvim_set_current_dir("C:/work")
else
  config_file = "~/.config/nvim/init.lua<CR>"
end

local project_dir = vim.fn.getcwd()

vim.o.completeopt="menu"
vim.cmd [[colorscheme bland]]

if vim.g.neovide then
  vim.o.guifont = "Consolas:h11.5"
  vim.g.neovide_scroll_animation_length = 0.3
  vim.g.neovide_transparency = 1.0
  vim.g.neovide_hide_mouse_when_typing = true
  vim.g.neovide_refresh_rate = 60 
  vim.g.neovide_refresh_rate_idle = 5
  vim.g.neovide_scroll_animation_length = 0.15
  vim.g.neovide_profiler = true
  vim.g.neovide_fullscreen = false
  vim.g.neovide_touch_drag_timeout = 0.17
  vim.g.neovide_cursor_animation_length= 0.08
  vim.g.neovide_cursor_trail_size = 0.2
end

local error_formats = 
{
  ["cpp"] = "%f(%l\\,%c): error %m", -- msbuild
  -- ["cpp"] = "%f:%l:%c: error: %m", -- clang
  ["c"] = "%f:%l:%c: error: %m", -- clang
  ["odin"] = "%f(%l:%c) %m",
}

local comments = 
{
  ["cpp"] = "//",
  ["c"] = "//",
  ["odin"] = "//",
  ["lua"] = "--",
}

local file_greps = 
{
  ["cpp"] = "**/*.cpp **/*.h **/*.hpp **/*.c",
  ["c"] = "**/*.cpp **/*.h **/*.hpp **/*.c",
  ["odin"] = "**/*.odin",
}

local function_regex_str =
{
  ["cpp"] = {"\\v^((\\w[*&]?)+\\s+){1,3}(\\w(::)?)+\\(.*", "\\v(\\w(::)?)+\\(.*"},
  ["lua"] = {"\\v^((\\w[*&]?)+\\s+){1,3}(\\w(::)?)+\\(.*", "\\v(\\w(::)?)+\\(.*"},
  ["c"] = {"\\v^((\\w[*&]?)+\\s+){1,3}(\\w(::)?)+\\(.*", "\\v(\\w(::)?)+\\(.*"},
  ["odin"] = {"\\v^(\\w+\\s+::\\s+(#\\w+\\s+){0,2}proc(\\s+\"\\w+\"\\s+)?\\()", "\\v^\\w+"},
}

local function set_build_command()
  local on_input = function(input)
    if input then
      build_command = input
    end
  end

  vim.ui.input({
    prompt = "Command:",
    default = build_command,
  }, on_input)
end

local function set_run_command()
  local on_input = function(input)
    if input then
      run_command = input
    end
  end

  vim.ui.input({
    prompt = "Command:",
    default = run_command,
  }, on_input)
end

local function set_project_directory()
  local on_input = function(input)
    if input then
      project_dir = input
    end
  end

  vim.ui.input({
    prompt = "Directory:",
    default = project_dir,
  }, on_input)

end


local function set_project_settings()
  set_build_command()
  set_run_command()
  set_project_directory()
end


-- Disable anoying error messages that are somehow always off the window
vim.lsp.handlers["textDocument/publishDiagnostics"] = vim.lsp.with(
vim.lsp.diagnostic.on_publish_diagnostics, {
  virtual_text = false
}
)

local qf_window_open = false
local qf_prev_win;

local function toggle_quickfix()
  if (qf_window_open) then
    vim.cmd(":cclose")
    qf_window_open = false;
    vim.api.nvim_set_current_win(prev_win)
  else
    prev_win = vim.api.nvim_get_current_win()
    vim.cmd(":copen")
    vim.cmd(":wincmd J")
    qf_window_open = true;
  end
end


local function build_project()
  local lines = {""}
  local bufnr = vim.api.nvim_win_get_buf(0)
  local previous_dir = vim.fn.getcwd()

  vim.cmd("cd " .. project_dir)
  local file_type = vim.bo.filetype

  print("Building...")

  local function on_event(job_id, data, event)
    if event == "stdout" or event == "stderr" then
      if data then
        vim.list_extend(lines, data)
      end
    end

    error_format = error_formats[file_type]
    print(error_format)

    if event == "exit" then
      vim.fn.setqflist({}, " ", {
        title = "Build",
        lines = lines,
        efm = error_format,
      })
    end

    -- bufnr != 0 seems like the only way to
    -- check if there are errors in the list 
    local qflist = vim.fn.getqflist()
    for i = 1, #qflist do
      if qflist[i].bufnr ~= 0 then
        print("Build failed.")
        vim.cmd("cd " .. previous_dir)
        return
      end
    end
    print("Build succeded.")
  end

  local job_id =
  vim.fn.jobstart(
  build_command,
  {
    on_stderr = on_event,
    on_stdout = on_event,
    on_exit = on_event,
    stdout_buffered = true,
    stderr_buffered = true,
  }
  )

  vim.cmd("cd " .. previous_dir)
end


local function run_project_impl(type)

  local function on_event(job_id, data, event)
    if event == "stdout" or event == "stderr" then
      if (data) then
        vim.fn.setqflist({}, "a", {
          title = "Run",
          lines = {data[1]},
        })
      end
    end
  end

  if type == "normal" then
    -- Clear the quickfix list
    vim.fn.setqflist({}, " ", {
      title = "Run",
      lines = {},
      --efm = "%f:%l:%c: error: %m",
    })

    vim.fn.jobstart(
    run_command,
    {
      on_stderr = on_event,
      on_stdout = on_event,
    })
  elseif type == "debug" then
    vim.fn.jobstart("remedybg start-debugging")
  end

end

local function run_project_debug()
  run_project_impl("debug")
end

local function run_project()
  run_project_impl("normal")
end


local function is_whitespace(char)
  return char == ' ' or char == '\t'
end

local function comment_line()

  local indent_regex = vim.regex("\\v^\\s*")
  local comment_regex = vim.regex("\\v^\\s*\\/\\/")
  local line = vim.api.nvim_get_current_line()

  if comment_regex.match_str(comment_regex, line) then
    line = string.gsub(line, "// ", "", 1)
  else
    local pre_string = ""

    for i = 1, #line do
      if (is_whitespace(string.sub(line, i, i))) then
        pre_string = pre_string .. " "
      else
        break;
      end
    end

    pre_string = pre_string .. "//"

    local s, e = indent_regex.match_str(indent_regex, line)
    if (e >= #pre_string - 2) then
      line = pre_string .. string.sub(line, #pre_string-2, -1)
    end
  end
  local cursor = vim.api.nvim_win_get_cursor(0)
  --print(row)
  vim.api.nvim_buf_set_lines(0, cursor[1]-1, cursor[1], true, {line});
end

local function comment_selection()
  local start_pos = vim.api.nvim_buf_get_mark(0, '<')[1]
  local end_pos = vim.api.nvim_buf_get_mark(0, '>')[1]
  local lines = vim.api.nvim_buf_get_lines(0, start_pos-1, end_pos, false)

  local indent_regex = vim.regex("\\v^\\s*")
  local comment_regex = vim.regex("\\v^\\s*\\/\\/")

  local is_commented = comment_regex.match_str(comment_regex, lines[1])

  if (is_commented) then
    for i = 1, #lines do
      local s, e = comment_regex.match_str(comment_regex, lines[i])
      if (e ~= 0) then
        lines[i] = string.gsub(lines[i], "// ", "", 1)
      end
    end
  else
    local pre_string = ""

    for i = 1, #lines[1] do
      if (is_whitespace(string.sub(lines[1], i, i))) then
        pre_string = pre_string .. " "
      else
        break;
      end
    end

    pre_string = pre_string .. "//"

    for i = 1, #lines do
      local s, e = indent_regex.match_str(indent_regex, lines[i])
      if (e >= #pre_string - 2) then
        lines[i] = pre_string .. string.sub(lines[i], #pre_string-2, -1)
      end
    end
  end

  vim.api.nvim_buf_set_lines(0, start_pos-1, end_pos, true, lines);
  --vim.api.nvim_win_set_cursor(vim.api.nvim_get_current_win(), end_pos)
end

local function cursor_move_impl(row_delta, col_delta)
  local pos = vim.api.nvim_win_get_cursor(0)
  pos[1] = pos[1] + row_delta;
  pos[2] = pos[2] + col_delta;
  vim.api.nvim_win_set_cursor(vim.api.nvim_get_current_win(), pos) 
end

local function replace_in_range()

end

local function cursor_move_left()
  cursor_move_impl(0, -1)
end

local function cursor_move_right()
  cursor_move_impl(0, 1)
end

local function cursor_move_up()
  cursor_move_impl(1, 0)
end

local function cursor_move_down()
  cursor_move_impl(-1, 0)
end

local pair_map = 
{
  [string.byte("(")]  = ")" ,
  [string.byte("{")]  = "}" ,
  [string.byte("[")]  = "]" ,
  [string.byte("\"")] = "\"",
  [string.byte("\'")] = "\'",
  [string.byte("<")]  = ">" ,
}


local function handle_pair(input, open, close)
  local pos = vim.api.nvim_win_get_cursor(0)
  local line = vim.api.nvim_get_current_line() 
  local char = line.byte(line, pos[2]+1)
  local input_char = string.byte(input)

  if (char == input_char) then
    return "<right>"
  else
    if (input == open) then
      local next_char = line.byte(line, pos[2]+2)
      if (next_char ~= string.byte(close)) then
        return open .. close .. "<left>"
      else
        return input
      end
    else
      return input
    end
  end
end


local function handle_open_paren() 
  return handle_pair('(', '(', ')')
end

local function handle_close_paren() 
  return handle_pair(')', '(', ')')
end

local function handle_open_brace() 
  return handle_pair('{', '{', '}')
end

local function handle_close_brace() 
  return handle_pair('}', '{', '}')
end

local function handle_open_bracket() 
  return handle_pair('[', '[', ']')
end

local function handle_close_bracket() 
  return handle_pair(']', '[', ']')
end

local function handle_open_angle_bracket() 
  return handle_pair('<', '<', '>')
end

local function handle_close_angle_bracket() 
  return handle_pair('>', '<', '>')
end

local function handle_quotes()
  return handle_pair('"', '"', '"')
end

local function handle_small_quotes()
  return handle_pair('\'', '\'', '\'')
end

local function handle_enter()
  local pos = vim.api.nvim_win_get_cursor(0)
  local line = vim.api.nvim_get_current_line() 
  local char = string.byte(line, pos[2])
  local next_char = string.byte(line, pos[2]+1)
  
  if char      == string.byte("{") and
     next_char == string.byte("}") then
    return "<CR>" .. "<CR>" .. "<up>" .. "<esc>" .. "S"
  else
    return "<CR>"
  end
end

local function handle_backspace()
  local pos = vim.api.nvim_win_get_cursor(0)
  local line = vim.api.nvim_get_current_line() 
  local char = string.byte(line, pos[2])
  local next_char = string.byte(line, pos[2]+1)
  
  if (next_char) then
    if pair_map[char] and
       string.byte(pair_map[char]) == next_char then
      return "<right>" .. "<backspace>" .. "<backspace>"
    else
      return "<backspace>"
    end
  else
    return "<backspace>"
  end
end

local function complete()
  if vim.fn.pumvisible() == 1 then
    return '<C-n>'
  else
    return '<C-x><C-o>'
  end
end

local function goto_function()

  local line_count = vim.api.nvim_buf_line_count(0)
  local lines = vim.api.nvim_buf_get_lines(0, 0, line_count, false)

  local regex1 = vim.regex(function_regex_str[vim.bo.filetype][1]);
  local regex2 = vim.regex(function_regex_str[vim.bo.filetype][2]);

  local function_list = {}
  local line_number_list = {}

  local on_input = function(input)
    if (input) then
      for i = 1, #function_list do
        if (function_list[i] == input) then
          local line_number = line_number_list[i]
          vim.api.nvim_win_set_cursor(vim.api.nvim_get_current_win(), {line_number, 0})
          return
        end
      end
    end
  end

  get_function_list = function(input, cmd_line, cursor_pos)
    function_list = {}
    line_number_list = {}
    for i = 1, line_count do 
      if (regex1.match_str(regex1, lines[i])) then
        if (string.find(lines[i], input)) then
          local name = string.sub(lines[i], regex2.match_str(regex2, lines[i]))
          table.insert(function_list, name)
          table.insert(line_number_list, i)
        end
      end
    end
    return function_list
  end

  vim.ui.input({
    prompt = "Go To Function:",
    completion = "customlist,v:lua.get_function_list",
  }, on_input)

end

-- Map a parser to language
-- local ft_to_parser = require"nvim-treesitter.parsers".filetype_to_parsername
-- ft_to_parser.cpp = "c"

-- Treesitter
require'nvim-treesitter.configs'.setup {
   --A list of parser names, or "all"
  ensure_installed = { "c", "cpp", "rust" },
  ignore_install = { "lua" },
   --Install parsers synchronously (only applied to `ensure_installed`)
  sync_install = false,

  -- Automatically install missing parsers when entering buffer
  -- Recommendation: set to false if you don't have `tree-sitter` CLI installed locally
  auto_install = false,
  indent = {
    enable = false
  },

  incremental_search = {
    enable = false,
  },

  highlight = {
    disable = {"lua"},
    enable = true,
    -- enable regex highlighting
    additional_vim_regex_highlighting = {"lua"},
  },
}

require"lsp_signature".setup {
  hi_parameter="IncSearch",
}
local parser_mapping = require("nvim-treesitter.parsers")
parser_mapping.cpp = "c"

local function grep_global()
  local on_input = function(input)
    vim.cmd("vimgrep " .. "\"" .. input .. "\"" .. "*.*")
  end
  vim.ui.input({
    prompt = "Grep:",
  }, on_input)
end

local function get_curr_buf_directory_path()
  local bufnr = vim.api.nvim_get_current_buf()
  local file_path = vim.api.nvim_buf_get_name(bufnr)
  local directory_path = vim.fn.fnamemodify(file_path, ":h")
  return directory_path;
end

local function grep_project_internal(use_file_dir)
  local directory = ""

  if use_file_dir then
    directory = get_curr_buf_directory_path()
  end

  local on_input = function(input)
      file_grep = file_greps[vim.bo.filetype]
      if file_grep ~= nil then
        vim.cmd("vimgrep " .. "\"" .. input .. "\"" .. directory .. file_grep)
      else
        vim.cmd("vimgrep " .. "\"" .. input .. "\"" .. directory .. "*.*")
        -- vim.api.nvim_err_writeln("N")
      end
  end

  vim.ui.input({
    prompt = "Grep:",
  }, on_input)
end

local function grep_project_file_dir()
  grep_project_internal(true)
end

local function grep_project_cwd()
  grep_project_internal(false)
end

local function set_cpp_buffer_options()
  vim.bo.complete = "i"
end

vim.api.nvim_create_autocmd(
"FileType",
{
  pattern = {"cpp", "h", "cc", "hpp"},
  callback = set_cpp_buffer_options
}
)

-- Options
-- vim.cmd[[set scl=no]]
vim.o.signcolumn="no"

vim.opt.relativenumber = false
vim.opt.gdefault = true
vim.opt.tabstop = 2
vim.opt.softtabstop = 2
vim.opt.shiftwidth = 2
vim.opt.expandtab = true
vim.opt.makeprg = "sh build.sh"
vim.opt.autowrite = true
vim.opt.errorformat = "%f:%l:%c: %m"

vim.opt.swapfile = false
vim.opt.backup = false
vim.opt.undofile = true
vim.opt.undodir = vim.env.HOME .. "/undodir"
vim.opt.hlsearch = true
vim.opt.wrap = true
vim.opt.linebreak = true
vim.opt.breakindent = true
vim.opt.showbreak = "››"
vim.opt.shellpipe = ">%s 2>&1" 

vim.opt.scrolloff = 8
vim.opt.updatetime = 50
vim.opt.guifont = {"JuliaMono:h10.4"}

-- Floaterm
vim.g.floaterm_position = "bottomright"
vim.g.floaterm_wintype = "float"
vim.g.floaterm_height = 0.5

-- Commands
--
vim.api.nvim_create_user_command("CommentSelection", comment_selection, {range = true})
vim.api.nvim_create_user_command("SetRunCommand", set_run_command, {})
vim.api.nvim_create_user_command("SetBuildCommand", set_build_command, {})
vim.api.nvim_create_user_command("SetProjectDirectory", set_project_directory, {})
vim.api.nvim_create_user_command("SetProjectSettings", set_project_settings, {})

-- Keybinds
vim.g.mapleader = " "
vim.keymap.set("n", "<A-e>", ":cnext<CR>")
vim.keymap.set("n", "<A-q>", ":cprevious<CR>")
vim.keymap.set("n", "R", vim.cmd.redo)
vim.keymap.set("n", "p", "P")
vim.keymap.set("n", "P", "\"+p")
vim.keymap.set("n", "{", ":<C-r>0")
vim.keymap.set("n", "}", ":<C-r>+")
vim.keymap.set("n", "<A-j>", "<C-d>")
vim.keymap.set("n", "<A-k>", "<C-u>")
vim.keymap.set("n", "<A-s>", ":w<CR>")
vim.keymap.set("n", "<A-w>", "<C-w>w")
vim.keymap.set("n", "<C-f>", "*")
vim.keymap.set("n", "<F7>", ":e " .. config_file)
vim.keymap.set("n", "<leader>d", vim.cmd.Ex)
vim.keymap.set("n", "<A-f>", ":e **/*")
vim.keymap.set("n", "<A-F>", ":e %:h/**/*")
vim.keymap.set("n", "<A-b>", ":b ")
vim.keymap.set("n", "<F3>", grep_project_cwd)
vim.keymap.set("n", "<S-F3>", grep_project_file_dir)
vim.keymap.set("n", "<C-F3>", grep_global)
vim.keymap.set("n", "`", toggle_quickfix)
--vim.keymap.set("n", "<C-t>", ":FloatermToggle<CR>")
vim.keymap.set("n", "<A-p>", goto_function)
vim.keymap.set("n", "<A-m>", build_project)
vim.keymap.set("n", "<F4>", run_project)
vim.keymap.set("n", "<F5>", run_project_debug)
vim.keymap.set("n", "<S-F5>", ":!remedybg stop-debugging<CR>")
vim.keymap.set("n", "<C-r>", "<C-q>");
vim.keymap.set("n", ",", "@m");
vim.keymap.set("n", "+", "vi{=");
vim.keymap.set("n", "<C-c>", comment_line);
vim.keymap.set("n", "m", "mm")
vim.keymap.set("n", "M", "g'm")
vim.keymap.set("n", "<C-o>", ":bnext<CR>")
vim.keymap.set("n", "<C-i>", ":bprevious<CR>")
vim.keymap.set("n", "<tab>", "")
vim.keymap.set("n", "<C-n>", "<C-^>")
vim.keymap.set("n", "<A-BS>", "ciw")

vim.keymap.set("v", "Y", "\"+y")
vim.keymap.set("v", "s", ":s/");
vim.keymap.set("v", "<C-c>", ":CommentSelection<CR>")

vim.keymap.set("i", "<tab>", complete, {expr = true})
vim.keymap.set("i", "<A-BS>", "<C-w>")
vim.keymap.set("i", "(", handle_open_paren, {expr = true})
vim.keymap.set("i", ")", handle_close_paren, {expr = true})
vim.keymap.set("i", "{", handle_open_brace, {expr = true})
vim.keymap.set("i", "}", handle_close_brace, {expr = true})
vim.keymap.set("i", "[", handle_open_bracket, {expr = true})
vim.keymap.set("i", "]", handle_close_bracket, {expr = true})
--vim.keymap.set("i", "<", handle_open_angle_bracket, {expr = true})
--vim.keymap.set("i", ">", handle_close_angle_bracket, {expr = true})
vim.keymap.set("i", "\"", handle_quotes, {expr = true})
vim.keymap.set("i", "\'", handle_small_quotes, {expr = true})
vim.keymap.set("i", "<backspace>", handle_backspace, {expr = true})
vim.keymap.set("i", "<CR>", handle_enter, {expr = true})

-- Plugins
vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
  use 'neovim/nvim-lspconfig' -- Configurations for Nvim LSP
  use 'wbthomason/packer.nvim'
  use "ray-x/lsp_signature.nvim"
  use 'nvim-treesitter/nvim-treesitter'
  use 'kalvinpearce/ShaderHighlight'
  use 'Tetralux/odin.vim'
  use 'sadotsoy/darkforce-vim'
  use 'teloe/bland.vim'
end)

