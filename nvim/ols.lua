local configs = require 'lspconfig/configs'
local util = require 'lspconfig/util'

configs.ols = {
    default_config = {
        cmd = {'ols'},
        filetypes = {"odin"},
        root_dir = util.root_pattern('ols.json'),
    }
}
