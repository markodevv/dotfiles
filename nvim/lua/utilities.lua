function _G.esc(str)
  return vim.api.nvim_replace_termcodes(str, true, false, true)
end

function _G.cd_current_file()
    return esc(':cd%:p:h<CR>:pwd<CR>')
end


