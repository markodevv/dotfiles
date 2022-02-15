-- TODO
-- C syntax higlighting?
--

local plug = vim.fn['plug#']
vim.call('plug#begin', '~/.config/nvim/plugged')

plug 'neovim/nvim-lspconfig'

vim.call('plug#end')

require 'utilities'
require 'lsp_settings'

local opt = vim.opt
local map = vim.api.nvim_set_keymap

local nvim_dir = 'C:/Users/Marko/AppData/Local/nvim'

opt.bg = 'dark'
-- Font
opt.guifont='Fantasque Sans Mono:h16:r'
--
--opt.syntax = 'on'
opt.showmatch = true
opt.errorbells = false
opt.belloff = 'all'
opt.tabstop = 4
opt.softtabstop = 4
opt.shiftwidth = 4
opt.backspace = {'indent', 'eol', 'start'}
opt.expandtab = true
-- Indenting
opt.autoindent = true
opt.smartindent = true
opt.cindent = true
-- Wraping
opt.wrap = true
opt.sidescroll = 5

-- Undo
opt.undofile = true
opt.undodir = nvim_dir .. '/undo'

opt.swapfile = true
opt.backup = false
opt.incsearch = true
opt.cursorline = true
opt.wildmenu = true
opt.cmdheight = 1

-- Show -- INSERT -- etc..
-- opt.showmode = false
--
-- Build file
opt.makeprg = 'sh build.sh -debug'


-- Mappings
local map_opts = {noremap = true}
local exp_map_opts = {expr = true, noremap = true}
map('n', 'cd', 'v:lua.cd_current_file()', exp_map_opts)

-- Buffer
map('n', '<m-b>', ':buffer ', map_opts)
map('n', '<C-b>', '<C-^>', map_opts)

-- Complete word
map('i', '<tab>', '<C-n>', map_opts)

-- Page up/down
map('n', '<m-j>', '<C-d>', map_opts)
map('n', '<m-k>', '<C-u>', map_opts)

-- Open file
map('n', '<m-f>', ':e ', map_opts)

-- Source config
map('n', '<F5>', ':source ' .. nvim_dir .. '/init.lua<CR>', map_opts)

-- Next/previous error
-- TODO
map('n', '<m-e>', ':cnext<CR>', map_opts)
map('n', '<m-q>', ':cprevious<CR>', map_opts)

-- Window Navigation
map('n', '<C-l>', '<C-w>l', map_opts)
map('n', '<C-h>', '<C-w>h', map_opts)
map('n', '<C-j>', '<C-w>j', map_opts)
map('n', '<C-k>', '<C-w>k', map_opts)

-- Redo
map('n', '<C-k>', '<C-w>k', map_opts)

-- Replace
-- map('v', '<C-r>', ':call ReplaceInRange()<CR>', map_opts)
-- map('n', '<C-r>', ':call ReplaceInBufferYN()<CR>', map_opts)

-- Save file
map('n', '<m-s>', ':w<CR>', map_opts)

-- Goto config file
map('n', '<F8>', ':e ' .. nvim_dir .. '/init.lua<CR>', map_opts)

-- Goto LSP settings file
map('n', '<F9>', ':e ~/AppData/Local/nvim/lua/lsp_settings.lua<CR>', map_opts)

-- Search word under cursor
map('n', '<C-/>', '*', map_opts)


--------

-- Vimscript code
vim.api.nvim_exec([[

colorscheme simple
set wildmode=longest:full,full
set completeopt-=preview

set errorformat+=%f(%l:%c)\ %m
nnoremap <m-g> :call GrepCppProject()<CR>
nnoremap <m-p> :call GoToFunction()<CR>
nnoremap <C-F5> :call PushCommit()<CR>

nnoremap <m-m> :call BuildProject()<CR>

nnoremap <C-d>d :call DeleteCurrentFile()<CR>
nnoremap <C-d><C-d> :call DeleteFile()<CR>

inoremap { <c-r>=InsertPair('{', '}')<CR>
inoremap ( <c-r>=InsertPair('(', ')')<CR>
inoremap [ <c-r>=InsertPair('[', ']')<CR>
inoremap < <c-r>=InsertPair('<', '>')<CR>

inoremap ) <c-r>=ClosePair(')')<CR>
inoremap ] <c-r>=ClosePair(']')<CR>
inoremap } <c-r>=ClosePair('}')<CR>
inoremap > <c-r>=ClosePair('>')<CR>

inoremap " <c-r>=InsertQuotes('"')<CR>
inoremap ' <c-r>=InsertQuotes("'")<CR>

inoremap <return> <c-r>=NewlineAndIndent()<CR>

set directory^=$HOME/.nvim_swap/

" Window settings
let g:neovide_cursor_animation_length=0.09

" Copy paste from other apps
nnoremap <S-p> "+p
vnoremap <S-y> "+y 


fun! NewlineAndIndent()
    let line = getline('.')
    let col = col('.')

    if line[col - 2] == '{' && line[col - 1] == '}'
        return "\<return>\<up>\<esc>o"
    endif

    return "\n"
endf

fun! ClosePair(char)
    if getline('.')[col('.') - 1] == a:char
        return "\<right>"
    else
        return a:char
    endif
endf


fun! InsertPair(open, close)
    let line = getline('.')
    let col = col('.')

    echo line[col]
    if line[col] == ' '  || col == col("$")
        return a:open.a:close."\<left>"
    endif

    return a:open
endf

fun! InsertQuotes(char) 
    let line = getline('.')
    let col = col('.')
    if line[col - 1] == a:char
        return "\<right>"
    else
        return a:char.a:char."\<left>"
    endif
endf



fun! QuoteDelim(char)
    let line = getline('.')
    let col = col('.')
    if line[col - 2] == "\\"
    "Inserting a quoted quotation mark into the string
    return a:char
    elseif line[col - 1] == a:char
    "Escaping out of the string
    return "\<Right>"
    else
    "Starting a string
    return a:char.a:char."\<Esc>i"
    endif
endf


fun! ReplaceInRange() range
    call inputsave()
    let replace = input("Replace: ")
    let with = input("With: ")
    call inputrestore()

    if (!empty(replace)) 
        execute a:firstline.",".a:lastline."s/".replace."/".with."/g"
    endif
endf

fun! ReplaceInBufferYN()
    call inputsave()
    let replace = input("Replace: ")
    let replace_with = input("With: ")
    call inputrestore()

    if (!empty(replace))
        execute ":%s/" . replace . "/" . replace_with . "/" . "gcI"
    else
        echo "Nothing to replace"
    endif

endf

function! GrepCppProject()

    call inputsave()
    let search_for = input("Search for: ")
    call inputrestore()

    if (len(search_for) > 0)
        execute ":vimgrep " . search_for . " " . "*.cpp *.c *.h *.hpp"
    endif

endfunction

nnoremap <F3> :call RenameFile()<CR>
fun! RenameFile()
    let new_file = expand('%:p:h') . '/'
    let old_file = expand('%:p')
    call inputsave()
    let new_file = new_file . input("New name: ")
    call inputrestore()

    execute "saveas " . new_file
    if has('unix')
        execute "silent !rm ".old_file
    elseif has ('win32')
        execute "silent !del /f ".old_file
    endif
endf

function! GetFunctionLineNumber(function_name)
    let file = readfile(expand("%:p")) " read current file
    let line_num = 1
    for line in file
        let match = stridx(line, a:function_name)
        if (match != -1)
            return line_num
        endif
        let line_num += 1
    endfor
    return -1
endfunction


"\v^(\S+\s*){1,5}\(.*\n
function! GetCFunctionNamesInFile(input, cmd, curs)
    let out = []
    let file = readfile(expand("%:p")) " read current file

    for line in file
        let match = matchstr(line, '^\(\S\+\s*\)\{1,5}(.*$')

        if (!empty(match))
            if (stridx(line, a:input) != -1)
                call add(out, match)
            endif
        endif
    endfor

    return out
endfunction


function! GoToFunction()
    call inputsave()
    let input_string = input("Go To Function: ", "", "customlist,GetCFunctionNamesInFile")
    call inputrestore()

    let line_num = GetFunctionLineNumber(input_string)
    if (line_num != -1 && line_num != 1)
        exe ":" . line_num
    endif

endfunction

function! DeleteCurrentFile()
    let filename = expand('%')
    call inputsave()
    let input_string = input("Delete file [" . filename . "] (Y/N)?: ", "")
    call inputrestore()

    if (input_string == "Y" || input_string == "y")
        execute "call delete(filename) | bdelete!"
    endif
endfunction

function! DeleteFile()
    call inputsave()
    let filename = input("File: ", "", "file")
    call inputrestore()

    if (!empty(filename))
        call inputsave()
        let input_string = input("Delete file [" . filename . "] (Y/N)?: ", "")
        call inputrestore()
        if (input_string == "Y" || input_string == "y")
            execute "call delete(filename) | bdelete!"
        endif
    endif


endfunction

function! PushCommit()
    call inputsave()
    let input_string = input("Commit message: ", "")
    call inputrestore()

    execute "!git add *" 
    execute "!git commit -m " . "\"" input_string "\""
    execute "!git push"
endfunction

function! BuildProject()
    execute "cd ../"
    execute "make"
    execute "cd src/"
endfunction

]], false)
-- Vimscript code end
