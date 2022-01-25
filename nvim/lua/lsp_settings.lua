local util = require 'utilities'
local lsp = require 'lspconfig'
local configs = require 'lspconfig/configs'


function _G.complete()
    if vim.fn.pumvisible() > 0 then
        return esc('<C-n>')
    else
        return esc('<c-x><c-o>')
    end
end

function _G.show_completion_on_dot() 
    return esc('.<c-x><c-o>')
end


configs.ols = {
    default_config = {
        cmd = {'ols'},
        filetypes = {"odin"},
        root_dir = require'lspconfig/util'.root_pattern('ols.json'),
    }
}

configs.clangd = {
    default_config = {
        cmd = {'clangd'},
        filetypes = {"cpp", "c", "hpp", "h"},
        root_dir = require'lspconfig/util'.root_pattern('compile_commands.json', 'compile_flags.txt'),
    }
}

configs.sumneko_lua = {
    default_config = {
        cmd = {'lua-language-server'},
        filetypes = {"lua"},
        root_dir = require'lspconfig/util'.root_pattern('.git') or bufdir,
	settings = {
		Lua = {
            runtime = {
                -- Tell the language server which version of Lua you're using (most likely LuaJIT in the case of Neovim)
                version = 'LuaJIT',
                -- Setup your lua path
                path = "C:\\Program Files\\LSP\\lua",
            },
            diagnostics = {
                -- Get the language server to recognize the `vim` global
                globals = {'vim'},
            },
            workspace = {
                    -- Make the server aware of Neovim runtime files
                library = vim.api.nvim_get_runtime_file("", true),
            },
			telemetry = {
				enable = false
			},
		}
	},
	single_file_support = true
    }
}



local on_attach = function(client, bufnr)
  local function buf_set_keymap(...) vim.api.nvim_buf_set_keymap(bufnr, ...) end
  local function buf_set_option(...) vim.api.nvim_buf_set_option(bufnr, ...) end

  -- Enable completion triggered by <c-x><c-o>
  buf_set_option('omnifunc', 'v:lua.vim.lsp.omnifunc')
  -- Mappings.
  buf_set_keymap('i', '<Tab>', 'v:lua.complete()', {expr = true, noremap = true})
  -- buf_set_keymap('i', '.', 'v:lua.show_completion_on_dot()', {expr = true, noremap = true})

  -- See `:help vim.lsp.*` for documentation on any of the below functions
  local opts = { noremap=true, silent=true }
  buf_set_keymap('n', 'gD', '<cmd>lua vim.lsp.buf.declaration()<CR>', opts)
  buf_set_keymap('n', 'gd', '<cmd>lua vim.lsp.buf.definition()<CR>', opts)
  buf_set_keymap('n', 'K', '<cmd>lua vim.lsp.buf.hover()<CR>', opts)
  buf_set_keymap('n', 'gi', '<cmd>lua vim.lsp.buf.implementation()<CR>', opts)
  buf_set_keymap('n', '<C-k>', '<cmd>lua vim.lsp.buf.signature_help()<CR>', opts)
  buf_set_keymap('i', '<C-k>', '<cmd>lua vim.lsp.buf.signature_help()<CR>', opts)
  buf_set_keymap('n', '<space>wa', '<cmd>lua vim.lsp.buf.add_workspace_folder()<CR>', opts)
  buf_set_keymap('n', '<space>wr', '<cmd>lua vim.lsp.buf.remove_workspace_folder()<CR>', opts)
  buf_set_keymap('n', '<space>wl', '<cmd>lua print(vim.inspect(vim.lsp.buf.list_workspace_folders()))<CR>', opts)
  buf_set_keymap('n', '<space>D', '<cmd>lua vim.lsp.buf.type_definition()<CR>', opts)
  buf_set_keymap('n', '<C-S-r>', '<cmd>lua vim.lsp.buf.rename()<CR>', opts)
  buf_set_keymap('n', '<space>ca', '<cmd>lua vim.lsp.buf.code_action()<CR>', opts)
  buf_set_keymap('n', 'gr', '<cmd>lua vim.lsp.buf.references()<CR>', opts)
  buf_set_keymap('n', '<space>e', '<cmd>lua vim.lsp.diagnostic.show_line_diagnostics()<CR>', opts)
  buf_set_keymap('n', 'gn', '<cmd>lua vim.lsp.diagnostic.goto_prev()<CR>', opts)
  buf_set_keymap('n', 'gp', '<cmd>lua vim.lsp.diagnostic.goto_next()<CR>', opts)
  buf_set_keymap('n', '<space>q', '<cmd>lua vim.lsp.diagnostic.set_loclist()<CR>', opts)
  buf_set_keymap('n', '<space>f', '<cmd>lua vim.lsp.buf.formatting()<CR>', opts)

end

local lsp_loaded = false;

local function load_lsp()
    if lsp_loaded == false then
        lsp.set_log_level = "debug"
        lsp.ols.setup{on_attach = on_attach}
        lsp.clangd.setup{on_attach = on_attach}
        lsp.sumneko_lua.setup{on_attach = on_attach}
        lsp_loaded = true
    end
end

load_lsp()


-- TODO not working
--lsp.sumneko_lua.setup{on_attach = on_attach}
