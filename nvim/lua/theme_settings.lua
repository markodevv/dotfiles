local theme = {}

function theme.set()
  vim.cmd [[
    " Vim color file
    " black
    " Created by  with ThemeCreator (https://github.com/mswift42/themecreator)

    hi clear

    if exists("syntax on")
    syntax reset
    endif

    set t_Co=256
    let g:colors_name = "black"

    " Define reusable colorvariables.
    let s:bg="#111111"
    let s:fg="#a9a384"
    let s:fg2="#a8a592"
    let s:fg3="#9a9686"
    let s:fg4="#8b8879"
    let s:bg2="#050505"
    let s:bg3="#292929"
    let s:bg4="#3d3d3d"
    let s:keyword="#3e7dca"
    let s:builtin="#0084ff"
    let s:const= "#c581b9"
    let s:comment="#808080"
    let s:func="#c33716"
    let s:str="#54a834"
    let s:preproc ="#c9761d"
    let s:type="#c9ac1d"
    let s:var="#b7b39f"
    let s:warning="#ff0000"
    let s:warning2="#ff8800"
    let s:select="#212121"
    let s:parameter="#292929"

    exe 'hi Normal guifg='s:fg' guibg='s:bg
    exe 'hi Visual guibg='s:select' gui=NONE'
    exe 'hi Cursor guifg='s:bg' guibg='s:fg
    exe 'hi CursorLine  guibg='s:bg2
    exe 'hi CursorLineNr guifg='s:str' guibg='s:bg
    exe 'hi CursorColumn  guibg='s:bg2
    exe 'hi ColorColumn  guibg='s:bg2
    exe 'hi LineNr guifg='s:fg2' guibg='s:bg2
    exe 'hi VertSplit guifg='s:fg3' guibg='s:bg3
    exe 'hi MatchParen guifg='s:warning2' guibg=NONE gui=underline'
    exe 'hi StatusLine guifg='s:fg2' guibg='s:bg3' gui=NONE'
    exe 'hi Pmenu guifg='s:fg' guibg='s:bg2
    exe 'hi PmenuSel  guibg='s:bg3
    exe 'hi IncSearch guibg='s:select' gui=NONE'
    exe 'hi Search guibg='s:select' guifg=NONE gui=NONE'
    exe 'hi LspSignatureActiveParameter guibg='s:parameter' gui=NONE'
    exe 'hi Directory guifg='s:const
    exe 'hi Folded guifg='s:fg4' guibg='s:bg
    exe 'hi WildMenu guifg='s:str' guibg='s:bg
    exe 'hi Boolean guifg='s:const
    exe 'hi Character guifg='s:const
    exe 'hi Comment guifg='s:comment
    exe 'hi Conditional guifg='s:keyword' gui=NONE'
    exe 'hi Constant guifg='s:const
    exe 'hi Todo guibg='s:bg
    exe 'hi Define guifg='s:keyword' gui=NONE'
    exe 'hi DiffAdd guifg=#fafafa guibg=#123d0f gui=NONE'
    exe 'hi DiffDelete guibg='s:bg2
    exe 'hi DiffChange  guibg=#151b3c guifg=#fafafa'
    exe 'hi DiffText guifg=#ffffff guibg=#ff0000 gui=NONE'
    exe 'hi ErrorMsg guifg='s:warning' guibg='s:bg2' gui=NONE'
    exe 'hi WarningMsg guifg='s:fg' guibg='s:warning2''
    exe 'hi Float guifg='s:const''
    exe 'hi Function guifg='s:func' gui=bold'
    exe 'hi Identifier guifg='s:fg' gui=NONE'
    exe 'hi Keyword guifg='s:keyword'  gui=NONE'
    exe 'hi Label guifg='s:var
    exe 'hi NonText guifg='s:bg4' guibg='s:bg2
    exe 'hi Number guifg='s:const
    exe 'hi Operator guifg='s:fg' gui=NONE'
    exe 'hi PreProc guifg='s:preproc' gui=NONE'
    exe 'hi Special guifg='s:fg
    exe 'hi SpecialKey guifg='s:fg2' guibg='s:bg2
    exe 'hi Statement guifg='s:keyword' gui=NONE'
    exe 'hi StorageClass guifg='s:type' gui=bold'
    exe 'hi String guifg='s:str
    exe 'hi Tag guifg='s:keyword' gui=NONE'
    exe 'hi Title guifg='s:fg'  gui=NONE'
    exe 'hi Todo guifg='s:fg2'  gui=inverse,NONE'
    exe 'hi Type guifg='s:type' gui=bold'
    exe 'hi Underlined   gui=underline'

    " Neovim Terminal Mode
    let g:terminal_color_0 = s:bg
    let g:terminal_color_1 = s:warning
    let g:terminal_color_2 = s:keyword
    let g:terminal_color_3 = s:bg4
    let g:terminal_color_4 = s:func
    let g:terminal_color_5 = s:builtin
    let g:terminal_color_6 = s:fg3
    let g:terminal_color_7 = s:str
    let g:terminal_color_8 = s:bg2
    let g:terminal_color_9 = s:warning2
    let g:terminal_color_10 = s:fg2
    let g:terminal_color_11 = s:var
    let g:terminal_color_12 = s:type
    let g:terminal_color_13 = s:const
    let g:terminal_color_14 = s:fg4
    let g:terminal_color_15 = s:comment

    " Ruby Highlighting
    exe 'hi rubyAttribute guifg='s:builtin
    exe 'hi rubyLocalVariableOrMethod guifg='s:var
    exe 'hi rubyGlobalVariable guifg='s:var' gui=italic'
    exe 'hi rubyInstanceVariable guifg='s:var
    exe 'hi rubyKeyword guifg='s:keyword
    exe 'hi rubyKeywordAsMethod guifg='s:keyword' gui=NONE'
    exe 'hi rubyClassDeclaration guifg='s:keyword' gui=NONE'
    exe 'hi rubyClass guifg='s:keyword' gui=NONE'
    exe 'hi rubyNumber guifg='s:const

    " Python Highlighting
    exe 'hi pythonBuiltinFunc guifg='s:builtin

    " Go Highlighting
    exe 'hi goBuiltins guifg='s:builtin
    let g:go_highlight_array_whitespace_error = 1
    let g:go_highlight_build_constraints      = 1
    let g:go_highlight_chan_whitespace_error  = 1
    let g:go_highlight_extra_types            = 1
    let g:go_highlight_fields                 = 1
    let g:go_highlight_format_strings         = 1
    let g:go_highlight_function_calls         = 1
    let g:go_highlight_function_parameters    = 1
    let g:go_highlight_functions              = 1
    let g:go_highlight_generate_tags          = 1
    let g:go_highlight_operators              = 1
    let g:go_highlight_space_tab_error        = 1
    let g:go_highlight_string_spellcheck      = 1
    let g:go_highlight_types                  = 1
    let g:go_highlight_variable_assignments   = 1
    let g:go_highlight_variable_declarations  = 1

    " Javascript Highlighting
    exe 'hi jsBuiltins guifg='s:builtin
    exe 'hi jsFunction guifg='s:keyword' gui=NONE'
    exe 'hi jsGlobalObjects guifg='s:type
    exe 'hi jsAssignmentExps guifg='s:var

    " Html Highlighting
    exe 'hi htmlLink guifg='s:var' gui=underline'
    exe 'hi htmlStatement guifg='s:keyword
    exe 'hi htmlSpecialTagName guifg='s:keyword

    " Markdown Highlighting
    exe 'hi mkdCode guifg='s:builtin
    ]]
end

return theme
