require("lsp_settings")
local theme = require("theme_settings")
local telescope = require("telescope.builtin")

local build_script =  "build.sh"
local run_command = "build\\game.exe" 

-- TODO: 
-- Git stuff, do i need it tho?
-- 

local function set_build_script(script)
  local on_input = function(input)
    build_script = input
  end

  vim.ui.input({
    prompt = ":",
  }, on_input)
end

local function set_run_command(command)
  local on_input = function(input)
    run_command = input
  end

  vim.ui.input({
    prompt = ":",
  }, on_input)
end

local function grep_search()
	telescope.grep_string({search = vim.fn.input("Grep: ")})
end

local function find_files_current_file_dir()
  telescope.find_files( { cwd = vim.fn.expand('%:p:h') })
end

local function build_project()
  vim.cmd("FloatermSend sh " .. build_script)
  vim.cmd("FloatermShow")
end

local function run_project()
  vim.cmd("FloatermSend " .. run_command)
  vim.cmd("FloatermShow")
end

local function project_start_debugging()
  vim.cmd("FloatermSend remedybg start-debugging")
end

local function project_stop_debugging()
  vim.cmd("FloatermSend remedybg stop-debugging")
end

local function hide_term()
  vim.cmd("FloatermHide")
end

local function is_whitespace(char)
  return char == ' ' or char == '\t'
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
      --print("NEXT " .. next_char .. " CLOSE " .. string.byte(close))
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

local pair_map = 
{
  [string.byte("(")] = ")",
  [string.byte("{")] = "}",
  [string.byte("[")] = "]",
  [string.byte("\"")] = "\"",
  [string.byte("\'")] = "\'",
  [string.byte("<")] = ">",
}

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

local function handle_backspace()
  local pos = vim.api.nvim_win_get_cursor(0)
  local line = vim.api.nvim_get_current_line() 
  local char = string.byte(line, pos[2])
  local next_char = string.byte(line, pos[2]+1)
  
  if (next_char) then
    if string.byte(pair_map[char]) == next_char then
      return "<right>" .. "<backspace>" .. "<backspace>"
    else
      return "<backspace>"
    end
  else
    return "<backspace>"
  end
end

local function goto_c_function()

  local line_count = vim.api.nvim_buf_line_count(0)
  local lines = vim.api.nvim_buf_get_lines(0, 0, line_count, false)

  local regex = vim.regex("\\v^((\\w[*&]?)+\\s+){1,3}\\w+\\(.*")
  local regex2 = vim.regex("\\v\\w+\\(.*")

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
      if (regex.match_str(regex, lines[i])) then
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


-- Treesitter
require'nvim-treesitter.configs'.setup {
  -- A list of parser names, or "all"
  ensure_installed = { "help", "cpp", "c", "hlsl", "glsl", "rust" },
  ignore_install = { "lua" },
  -- Install parsers synchronously (only applied to `ensure_installed`)
  sync_install = false,

  -- Automatically install missing parsers when entering buffer
  -- Recommendation: set to false if you don't have `tree-sitter` CLI installed locally
  auto_install = false,

  highlight = {
    disable = {"lua"},
    enable = true,
    -- enable regex highlighting
    additional_vim_regex_highlighting = {"lua"},
  },
}
-- Options
vim.opt.nu = true
vim.opt.tabstop = 2
vim.opt.softtabstop = 2
vim.opt.shiftwidth = 2
vim.opt.expandtab = true

vim.opt.swapfile = false
vim.opt.backup = false
vim.opt.undofile = true
vim.opt.undodir = vim.env.HOME .. "/undodir"
vim.opt.hlsearch = true
vim.opt.wrap = false

theme.set()

vim.opt.scrolloff = 8
vim.opt.updatetime = 50
vim.opt.guifont = {"JuliaMono:h10.4"}

-- Neovide
vim.g.neovide_transparency = 1.0
vim.g.neovide_hide_mouse_when_typing = true
vim.g.neovide_refresh_rate = 60 
vim.g.neovide_refresh_rate_idle = 5
vim.g.neovide_scroll_animation_length = 0.2
vim.g.neovide_profiler = false

-- Floaterm
vim.g.floaterm_position = "bottomright"
vim.g.floaterm_wintype = "float"
vim.g.floaterm_height = 0.5

-- Commands
--
vim.api.nvim_create_user_command("CommentSelection", comment_selection, {range = true})
vim.api.nvim_create_user_command("SetRunCommand", set_run_command, {})
vim.api.nvim_create_user_command("SetBuildScript", set_build_script, {})

-- Keybinds
vim.g.mapleader = " "
vim.keymap.set("n", "R", vim.cmd.redo)
vim.keymap.set("n", "p", "P")
vim.keymap.set("n", "P", "\"+p")
vim.keymap.set("n", "{", ":<C-r>0")
vim.keymap.set("n", "}", ":<C-r>+")
vim.keymap.set("n", "<A-j>", "<C-d>")
vim.keymap.set("n", "<A-k>", "<C-u>")
vim.keymap.set("n", "<A-s>", ":w<CR>")
vim.keymap.set("n", "<A-w>", "<C-w>w")
vim.keymap.set("n", "<C-f>", "yiw/<C-r>0")
vim.keymap.set("n", "<F7>", ":e ~/AppData/Local/nvim/init.lua<CR>")
vim.keymap.set("n", "<leader>d", vim.cmd.Ex)
vim.keymap.set("n", "<A-f>", telescope.find_files, {})
vim.keymap.set("n", "<A-S-f>", find_files_current_file_dir)
vim.keymap.set("n", "<F3>", grep_search)
--vim.keymap.set("n", "<A-f>", telescope.git_files, {})
vim.keymap.set("n", "`", ":FloatermToggle<CR>")
vim.keymap.set("n", "<A-p>", goto_c_function);
vim.keymap.set("n", "<A-m>", build_project)
vim.keymap.set("n", "<F4>", run_project)
vim.keymap.set("n", "<F5>", project_start_debugging)
vim.keymap.set("n", "<S-F5>", project_stop_debugging)
vim.keymap.set("n", "<C-r>", "<C-q>");
vim.keymap.set("n", ",", "@m");

vim.keymap.set("t", "<esc>", hide_term)
vim.keymap.set("t", "`", hide_term)

vim.keymap.set("v", "Y", "\"+y")
vim.keymap.set("v", "s", ":s/");
vim.keymap.set("v", "<C-c>", ":CommentSelection<CR>")

vim.keymap.set("i", "<tab>", "<C-n>")
vim.keymap.set("i", "(", handle_open_paren, {expr = true})
vim.keymap.set("i", ")", handle_close_paren, {expr = true})
vim.keymap.set("i", "{", handle_open_brace, {expr = true})
vim.keymap.set("i", "}", handle_close_brace, {expr = true})
vim.keymap.set("i", "[", handle_open_bracket, {expr = true})
vim.keymap.set("i", "]", handle_close_bracket, {expr = true})
vim.keymap.set("i", "<", handle_open_angle_bracket, {expr = true})
vim.keymap.set("i", ">", handle_close_angle_bracket, {expr = true})
vim.keymap.set("i", "\"", handle_quotes, {expr = true})
vim.keymap.set("i", "\'", handle_small_quotes, {expr = true})
vim.keymap.set("i", "<backspace>", handle_backspace, {expr = true})


-- Plugins
vim.cmd [[packadd packer.nvim]]
return require('packer').startup(function(use)
  use 'neovim/nvim-lspconfig' -- Configurations for Nvim LSP
  use 'wbthomason/packer.nvim'
  use 'voldikss/vim-floaterm'
  use {
    'nvim-telescope/telescope.nvim', tag = '0.1.0',
    requires = { {'nvim-lua/plenary.nvim'} }
  }
  use {
    "ray-x/lsp_signature.nvim",
  } 
  use {
    'nvim-treesitter/nvim-treesitter',
    run = ':TSUpdate'
  }
  use "rebelot/kanagawa.nvim"
end)

