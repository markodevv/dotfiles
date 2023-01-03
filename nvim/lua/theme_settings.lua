local theme = {}

local default_colors = require("kanagawa.colors").setup()
local theme_colors = 
{
    kw = "#DCD7BA",
}
local theme_overrides = 
{
  -- override existing hl-groups, the new keywords are merged with existing ones
  Identifier = { fg = default_colors.fg },
}

function theme.set()
  require('kanagawa').setup({
    undercurl = true,           -- enable undercurls
    commentStyle = { italic = true },
    functionStyle = {},
    keywordStyle = { italic = false },
    statementStyle = { bold = false },
    typeStyle = {},
    variablebuiltinStyle = { italic = true},
    specialReturn = true,       -- special highlight for the return keyword
    specialException = true,    -- special highlight for exception handling keywords
    transparent = false,        -- do not set background color
    dimInactive = false,        -- dim inactive window `:h hl-NormalNC`
    globalStatus = false,       -- adjust window separators highlight for laststatus=3
    terminalColors = true,      -- define vim.g.terminal_color_{0,17}
    colors = theme_colors,
    overrides = theme_overrides,
    theme = "default"           -- Load "default" theme or the experimental "light" theme
  })
  vim.cmd.colorscheme("kanagawa")
end

return theme

