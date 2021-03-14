" TODO: commenting code
" TODO: running app

colorscheme gruvbox
set guioptions-=T
set guioptions-=m
set guioptions-=L
set guioptions-=r

set t_Co=256
syntax on

set showmatch
set noerrorbells
set belloff=all
set tabstop=4 softtabstop=4
set shiftwidth=4
set backspace=2
set expandtab
set smartindent
set nu
set nowrap
set noswapfile
set nobackup
set undodir=~/.vim/undodir
set undofile
set incsearch
set cursorline
set guifont=DejaVu_Sans_Mono:h11

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

inoremap { {<CR>}<Esc>ko
inoremap ( ()<Esc>i


" kill current window

function! SwitchWindow()
    execute "normal \<m-w>"
endfunction

function! CharAtIdx(str, idx) abort                                       
  " Get char at idx from str. Note that this is based on character index  
  " instead of the byte index.                                            
  return strcharpart(a:str, a:idx, 1)                                     
endfunction
                                                                          
function! CursorCharIdx() abort                                           
  " A more concise way to get character index under cursor.               
  let cursor_byte_idx = col('.')                                          
  if cursor_byte_idx == 1                        
    return 0                      
  endif                                                                   
                             
  let pre_cursor_text = getline('.')[:col('.')-2]                         
  return strchars(pre_cursor_text)                                        
endfunction

function! CharAfterCursor()
    let cursor_char_idx = CursorCharIdx()
    let cur_char = CharAtIdx(getline('.'), cursor_char_idx + 1)
    return cur_char
endfunction

function! SkipParen()
    if CharAfterCursor() == ')'
       execute "normal l"
       echom "trueeee"
    else
       return ")"
    endif
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

" search regex \v^(<\w+>\s*)\(
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

function! AllFileFunctionsNamesMap()
    let out = {1 : ""}
    let file = readfile(expand("%:p")) " read current file
    let line_num = 1
    for line in file
        let match = matchstr(line, '\v^(<\w+>\s*)\(')
        if (!empty(match))
            let out[match] = line_num
        endif
        let line_num += 1
    endfor
    return out
endfunction

function! GoToFunction()
    call inputsave()
    let input_string = input("Function name: ", "", "customlist,AllFileFunctionsNames")
    call inputrestore()

    let function_name_map = AllFileFunctionsNamesMap()
    exe function_name_map[input_string]

    echom input_string

endfunction


nnoremap <m-m> :call CompileProject(".")<CR>
nnoremap <m-p> :call GoToFunction()<CR>
