" TODO: commenting code
" TODO: running app
" TODO: make vim auto add user defined struct as syntax highliting information

colorscheme gruvbox
set guioptions-=T
set guioptions-=m
set guioptions-=L
set guioptions-=r

set t_Co=256
syntax on

behave mswin
set t_vb=on
set showmatch
set noerrorbells
set belloff=all
set tabstop=4 softtabstop=4
set shiftwidth=4
set backspace=2
set expandtab
set smartindent
set autoindent
set nu
set nowrap
set noswapfile
set nobackup
set undodir=~/.vim/undodir
set undofile
set incsearch
set cursorline
set guifont=Liberation_Mono:h10.9

set wildmenu
set wildmode=longest:full,full
" save file
map <m-s> :w<CR>
" switch to coresponding cpp/h file
map <m-c> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,<CR>
" source config file
map <m-S-r> :source ~/.vimrc<CR>
" find file
map <m-f> :e 
" find buffer
map <m-b> :buffer 
" switch to other window
map <m-w> <c-w><c-w>
" complete word
inoremap <Tab> <C-n>
" scrolling window
map <m-j> <C-d>
" switch to other window
map <m-k> <C-u>

nnoremap <m-p> :call GoToFunction()<CR>
nnoremap <m-m> :call CompilePopup(".")<CR>
nnoremap <m-=> :call CompilePopupClose()<CR>

inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap { {<CR>}<Esc>O
autocmd Syntax html,vim inoremap < <lt>><Esc>i| inoremap > <c-r>=ClosePair('>')<CR>
inoremap ) <c-r>=ClosePair(')')<CR>
inoremap ] <c-r>=ClosePair(']')<CR>
inoremap } <c-r>=CloseBracket()<CR>
inoremap " <c-r>=QuoteDelim('"')<CR>
inoremap ' <c-r>=QuoteDelim("'")<CR>


function! SwitchWindow()
    execute "normal \<m-w>"
endfunction


function! CompileProject(directory)

    let file_list = split(globpath(a:directory, '*'), '\n')

    for file_path in file_list
        let file_path_split = split(file_path, '\')
        let file_name_index = len(file_path_split) - 1
        " echom file_path_split[file_name_index] 
        if file_path_split[file_name_index] == "build.bat"
            let path_to_file = file_path[:-10]
            exe 'cd ' . path_to_file
            let window_count = 0
            windo let window_count = window_count + 1

            if window_count == 1
                execute "normal \<c-w>v"
                call SwitchWindow()
                exe 'terminal ++curwin ' . file_path_split[file_name_index]
                call SwitchWindow()
            else
                exe 'terminal ++curwin ' . file_path_split[file_name_index]
                call SwitchWindow()
            endif
        elseif isdirectory(file_path)
            call CompileProject(file_path)
        endif
    endfor

endfunction

" function search regex:\v^(<\w+>\s*)\(
function! AllFileFunctionsNames(input, cmd, curs)
    let out = []
    let file = readfile(expand("%:p")) " read current file
    for line in file
        let match = matchstr(line, '\v^(<\w+>\s*)\(')
        if (!empty(match))
            if (stridx(match, a:input) != -1)
                call add(out, match)
                echo match
            endif
        endif
    endfor
    return out
endfunction

function! GetFunctionLineNumber(function_name)
    let file = readfile(expand("%:p")) " read current file
    let line_num = 1
    for line in file
        let match = matchstr(line, a:function_name)
        if (!empty(match))
            return line_num
        endif
        let line_num += 1
    endfor
    return -1
endfunction

function! GoToFunction()
    call inputsave()
    let input_string = input("Function name: ", "", "customlist,AllFileFunctionsNames")
    call inputrestore()

    let function_line_number = GetFunctionLineNumber(input_string)

    if (function_line_number != -1)
        exe function_line_number
    endif

endfunction

function! CompilePopup(directory)
    let file_list = split(globpath(a:directory, '*'), '\n')

    for file_path in file_list
        let file_path_split = split(file_path, '\')
        let file_name_index = len(file_path_split) - 1
        " echom file_path_split[file_name_index] 
        if file_path_split[file_name_index] == "build.bat"
            let path_to_file = file_path[:-10]
            exe 'cd ' . path_to_file

            let popup_args = {'posinvert':'FALSE', 'minwidth':204, 'minheight':30, 'col':1, 'line':25, 'border':[1]}
            let buf = term_start("build.bat", #{hidden: 1})
            let winid = popup_create(buf, popup_args)
            hi! win_color gui=NONE guibg=Grey15 guifg=NavajoWhite1
            call win_execute(winid, 'setlocal wincolor=win_color')


        elseif isdirectory(file_path)
            call CompilePopup(file_path)
        endif
    endfor
endfunction

function! CompilePopupClose()
    exe 'exit'
    call popup_clear()
endfunction

function ClosePair(char)
 if getline('.')[col('.') - 1] == a:char
 return "\<Right>"
 else
 return a:char
 endif
endf

function CloseBracket()
 if match(getline(line('.') + 1), '\s*}') < 0
 return "\<CR>}"
 else
 return "\<Esc>j0f}a"
 endif
endf

function QuoteDelim(char)
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

