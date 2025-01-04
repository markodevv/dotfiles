require("lsp_settings")

-- TODO --
-- [x] Running project
-- [x] Running project trough debugger
-- [x] Fix quickfix error output (everything is 1 line)
-- [x] Fail build on link errors
-- [ ] Displaying output from running app
-- [x] Don't build if building process already started
-- [x] Setting/Jumping to mark
-- [x] Grep project
-- [x] Make completion prioritize closer words
-- [ ] Make completion work on improted packages
-- [ ] Comment/Uncomment

-- Package manager setup --

vim.cmd [[packadd packer.nvim]]

require('packer').startup(function(use)
  use 'neovim/nvim-lspconfig'
  use 'wbthomason/packer.nvim'
  use "ray-x/lsp_signature.nvim"
  use "Tetralux/odin.vim"
end);

------------------

-- Plugin configs --

local lspconfig = require("lspconfig")

-- Mappings.
-- See `:help vim.diagnostic.*` for documentation on any of the below functions
local opts = { noremap=true, silent=true }
--vim.keymap.set('n', '<space>e', vim.diagnostic.open_float, opts)
--vim.keymap.set('n', '<space>q', vim.diagnostic.goto_prev, opts)
--vim.keymap.set('n', '<space>e', vim.diagnostic.goto_next, opts)
--vim.keymap.set('n', '<space>q', vim.diagnostic.setloclist, opts)

-- Use an on_attach function to only map the following keys
-- after the language server attaches to the current buffer
local on_attach = function(client, bufnr)
  -- Enable lsp signature plugin
  require "lsp_signature".on_attach({
    bind = true,
    floating_window = true, 
    wrap = true,
    hint_enable = false,
    handler_opts = {
      border = "none"
    }
  }, bufnr)

  -- Enable completion triggered by <c-x><c-o>
  vim.api.nvim_buf_set_option(bufnr, 'omnifunc', 'v:lua.vim.lsp.omnifunc')
  -- Mappings.
  -- See `:help vim.lsp.*` for documentation on any of the below functions
  local bufopts = { noremap=true, silent=true, buffer=bufnr }
  vim.keymap.set('n', 'gD', vim.lsp.buf.declaration, bufopts)
  vim.keymap.set('n', 'gd', vim.lsp.buf.definition, bufopts)
  vim.keymap.set('n', 'K', vim.lsp.buf.hover, bufopts)
  vim.keymap.set('n', 'gi', vim.lsp.buf.implementation, bufopts)
  --vim.keymap.set('n', '<C-k>', vim.lsp.buf.signature_help, bufopts)
  --vim.keymap.set('n', '<space>wa', vim.lsp.buf.add_workspace_folder, bufopts)
  --vim.keymap.set('n', '<space>wr', vim.lsp.buf.remove_workspace_folder, bufopts)
  --vim.keymap.set('n', '<space>wl', function()
    --print(vim.inspect(vim.lsp.buf.list_workspace_folders()))
  --end, bufopts)
  vim.keymap.set('n', '<space>D', vim.lsp.buf.type_definition, bufopts)
  vim.keymap.set('n', '<F2>', vim.lsp.buf.rename, bufopts)
  --vim.keymap.set('n', '<space>ca', vim.lsp.buf.code_action, bufopts)
  vim.keymap.set('n', 'gr', vim.lsp.buf.references, bufopts)
  --vim.keymap.set('n', '<space>f', function() vim.lsp.buf.format { async = true } end, bufopts)
end

local lsp_flags = {
  -- This is the default in Nvim 0.7+
  debounce_text_changes = 150,
}

require'lspconfig'.ols.setup{
  on_attach = on_attach,
  flags = lsp_flags,
}

-- Disable anoying diagnostics
vim.diagnostic.disable();

--require('lspconfig')['clangd'].setup{
--  on_attach = on_attach,
--  flags = lsp_flags,
--}

require"lsp_signature".setup {
  hi_parameter="IncSearch",
}

------------------

config_file = "~/AppData/Local/nvim/init.lua<CR>"

-- Options --

vim.g.mapleader = " "
vim.g.maplocalleader = "\\"
vim.o.completeopt="menu"
vim.o.signcolumn="no"
vim.opt.complete = '.,w'
vim.opt.pumheight = 4 
vim.opt.relativenumber = false
vim.opt.gdefault = true
vim.opt.tabstop = 2
vim.opt.softtabstop = 2
vim.opt.shiftwidth = 2
vim.opt.expandtab = true
vim.opt.swapfile = false
vim.opt.undofile = true
vim.opt.undodir = vim.env.HOME .. "/undodir"
vim.opt.hlsearch = false
vim.opt.scrolloff = 8
vim.opt.cmdheight = 2
vim.cmd.colorscheme("retrobox");

------------------

-- Variables --

local qf_window_open = false
local qf_prev_win;

local build_cmd = "py build.py" 
local language = "odin"
local lang_list = {
  "odin",
  "cpp",
  "c",
}

local project_dir = vim.fn.getcwd();
local app_exe
local project_dir

local error_formats = 
{
  ["cpp"] = "%f(%l\\,%c): error %m", -- msbuild
  -- ["cpp"] = "%f:%l:%c: error: %m", -- clang
  ["c"] = "%f:%l:%c: error: %m", -- clang
  ["odin"] = "%f(%l:%c) %m",
}

local file_greps = 
{
  ["cpp"] = "**/*.cpp **/*.h **/*.hpp **/*.c",
  ["c"] = "**/*.cpp **/*.h **/*.hpp **/*.c",
  ["odin"] = "**/*.odin",
}


local build_start_time;
local building_in_progress = false

---------------

-- Functions --

local function normalize_spaces(text)
  return text:match("^%s*(.-)%s*$"):gsub("%s+", " ")
end

local function on_exit(obj)
  
  vim.schedule(function() 

    local error_format = error_formats[language]

    local output_lines = vim.split(obj.stdout, "\n", {plain = true})

    local function build_done(success)
      local elapsed = os.clock() - build_start_time; 
      building_in_progress = false
      if success then
        print(string.format("Build SUCCESS - %.2f ms", elapsed * 1000))
      else
        print(string.format("Build FAILED - %.2f ms", elapsed * 1000))
      end
    end

    if #obj.stdout > 1 then
      vim.fn.setqflist({}, " ", {
        title = "Build",
        lines = output_lines,
        --efm = error_format,
      })
      if string.find(obj.stdout, "LINK : fatal error") ~= nil then
        return build_done(false)
      end
    end

    local error_lines = vim.split(obj.stderr, "\n", {plain = true})
    if #obj.stderr > 1 then
      vim.fn.setqflist({}, " ", {
        title = "Build",
        lines = error_lines,
        efm = error_format,
      })
    end

    -- bufnr != 0 seems like the only way to
    -- check if there are errors in the list 
    local qflist = vim.fn.getqflist()
    for i = 1, #qflist do
      if qflist[i].bufnr ~= 0 then
        return build_done(false)
      end
    end

    return build_done(true)

  end)
end

local function build_project()
  if building_in_progress then
    return
  end
  print("Building..");
  building_in_progress = true
  build_start_time = os.clock()
  vim.system({"py", "build.py"}, {text = true}, on_exit);
end

local function complete()
  if vim.fn.pumvisible() == 1 then
    return '<C-n>'
  else
    return '<C-p>'
  end
end


local function lsp_complete()
  if vim.fn.pumvisible() == 1 then
    return '<C-n>'
  else
    return '<C-x><C-o>'
  end
end

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

local function move_left_no_block()
  local col = vim.fn.col('.')
  local line = vim.fn.line('.')
  if col == 1 and line > 1 then
    -- Move to the end of the previous line
    return "k$"
  end

  return "h"
end

local function custom_visual_yank()
  local mode = vim.fn.visualmode();
  if mode == "V" then
    return "y"
  end
  return move_left_no_block() .. "y";
end

local function custom_visual_cut()
  local mode = vim.fn.visualmode();
  if mode == "V" then
    return "c"
  end
  return move_left_no_block() .. "c";
end

local function custom_visual_delete()
  local mode = vim.fn.visualmode();
  if mode == "V" then
    return "d"
  end
  return move_left_no_block() .. "d";
end

local function custom_cnext()
  local qflist = vim.fn.getqflist()
  local error_count = 0;
  for i = 1, #qflist do
    -- Seems like only way to test if line is actually an error...
    if qflist[i].lnum ~= 0 then
      error_count = error_count + 1
    end

    if error_count > 1 then
      break
    end
  end

  if error_count > 1 then
    return ":cnext<CR>"
  else
    return ":crewind<CR>"
  end
end

local function mark()
  local a_mark = vim.api.nvim_get_mark("A", {})
  if a_mark[1] == 0 and 
    a_mark[2] == 0 and 
    a_mark[3] == 0 and 
    a_mark[4] == "" then
    -- set mark
    vim.cmd("mark A")
  else
    -- goto mark
    vim.cmd("normal! 'A")
    vim.cmd("delmarks A")
  end
end

local function grep_internal(directory, pattern)

  --if use_file_dir then
    --directory = get_curr_buf_directory_path()
  --end
  if patter == "" then
    print("ERROR - No search pattern for this grep.")
  end

  local on_input = function(input)
    vim.cmd("silent! vimgrep " .. "\"" .. input .. "\"" .. directory .. pattern)
  end

  vim.ui.input({
    prompt = "Project grep:",
  }, on_input)
end

local function project_grep()
  file_grep = file_greps[language]
  grep_internal("", file_grep)
end

local function grep()
  grep_internal("", "*.*")
end

local function valid_language(lang)
  for i = 0, #lang_list do
    if lang_list[i] == lang then
      return true
    end
  end
  return false
end

local function run_project()
  if app_exe == "" or project_dir == "" then 
    return 
  end

  vim.uv.spawn(project_dir .. "/build/" .. app_exe, {hide = false, detached = true})
end

local function raddbg_run_project()
  if app_exe == "" or project_dir == "" then 
    return 
  end


  vim.uv.spawn("raddbg.exe", {
    hide = false,
    args = {"--project:" .. project_dir .. "/game", "--ipc", "launch_and_run", }, 
    detached = true}
    )
  --vim.uv.spawn(project_dir .. "/build/" .. app_exe, {hide = false, detached = true})
end

local function raddbg_add_breakpoint()
 -- `raddbg --ipc find_code_location \"c:/foo/bar/baz.c:123:1\"` `--ipc`
  local current_file = vim.fn.expand('%:p')
  local line = vim.fn.line('.')
  local col = vim.fn.col('.')
  print("add_breakpoint \"" .. current_file .. ":" .. line .. "\"")

  vim.uv.spawn("raddbg.exe", {
    hide = false,
    args = {
      "--project:" .. project_dir .. "/game", 
      "--ipc", 
      "add_breakpoint:" .. "\"" .. current_file .. ":" .. line .. "\""
      }, 
    detached = true}
    )
 
end

local function raddbg_kill_all()

  vim.uv.spawn("raddbg.exe", {
    hide = false,
    args = {
      "--project:" .. project_dir .. "/game", 
      "--ipc", 
      "kill_all"
      }, 
    detached = true}
    )
 
end

local function load_project()
  local lines = vim.fn.readfile("./project.txt")

  if #lines == 0 then
    print("No 'project.txt' found.")
    return
  end

  --vim.uv.disable_stdio_inheritance()

  project_dir = vim.fn.getcwd();

  for i = 1, #lines do
    --print(lines[i])
    local parts = vim.split(lines[i], "%s+", {trimempty = true})
    if #parts > 1 then
      if parts[1] == "language" then
        if valid_language(parts[2]) then
          language = parts[2]
        end
      elseif parts[1] == "app_exe" then
        app_exe = parts[2];
      end
    end
  end

  print("Loaded project settings 'project.txt'")
  print("  language    - " .. language)
  print("  app_exe     - " .. app_exe)
  print("  project_dir - " .. project_dir)
end

vim.api.nvim_create_user_command("LoadProject",          load_project, {})
vim.api.nvim_create_user_command("RunProject",           run_project,  {})
vim.api.nvim_create_user_command("RaddbgRun",            raddbg_run_project,  {})
vim.api.nvim_create_user_command("RaddbgAddBreakpoint",  raddbg_add_breakpoint,  {})

------------------

-- Startup functions --

load_project()

------------------

-- Key mappings --

vim.g.mapleader = " "
vim.keymap.set("n", "<A-e>", custom_cnext, {expr = true})
vim.keymap.set("n", "<A-q>", ":cprevious<CR>")
vim.keymap.set("n", "<A-j>", "<C-d>")
vim.keymap.set("n", "<A-k>", "<C-u>")
vim.keymap.set("n", "<A-w>", "<C-w>w")
vim.keymap.set("n", "<C-i>", ":b ")
vim.keymap.set("n", "<C-o>", ":e **/*")
vim.keymap.set("n", "<A-s>", ":w<CR>")
vim.keymap.set("n", "p", "P")
vim.keymap.set("n", "P", "\"+p")
vim.keymap.set("n", "<F7>", ":e " .. config_file)
vim.keymap.set("n", "R", vim.cmd.redo)
vim.keymap.set("n", "`", toggle_quickfix)
vim.keymap.set("n", "<C-f>", "*")
vim.keymap.set("n", "<C-n>", "<C-^>")
vim.keymap.set("n", "<A-m>", build_project)
vim.keymap.set("n", "<S-F3>", grep)
vim.keymap.set("n", "m", mark)
vim.keymap.set("n", "<F3>", project_grep)
vim.keymap.set("n", "<F5>", run_project)
vim.keymap.set("n", "<F6>", raddbg_run_project)
vim.keymap.set("n", "<F8>", raddbg_add_breakpoint)
vim.keymap.set("n", "<S-F6>", raddbg_kill_all)

vim.keymap.set("v", "y", custom_visual_yank, {expr = true})
vim.keymap.set("v", "c", custom_visual_cut, {expr = true})
vim.keymap.set("v", "d", custom_visual_delete, {expr = true})

vim.keymap.set("i", "<C-t>", lsp_complete, {expr = true})
vim.keymap.set("i", "<tab>", complete, {expr = true})
vim.keymap.set("i", "<C-BS>", "<C-w>")
vim.keymap.set("i", "<C-H>", "<C-w>")

------------------
