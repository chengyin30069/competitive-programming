set nocompatible
filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'

Plugin 'scrooloose/nerdtree'

Plugin 'tpope/vim-commentary'

Plugin 'mhinz/vim-startify'

Plugin 'vim-airline/vim-airline'

Plugin 'vim-airline/vim-airline-themes'

Plugin 'flazz/vim-colorschemes'

Plugin 'tribela/vim-transparent'

Plugin 'vimsence/vimsence'

Plugin 'christoomey/vim-tmux-navigator'

Plugin 'bfrg/vim-cpp-modern'

call vundle#end()

filetype plugin indent on

let g:airline#extensions#tabline#enabled = 1

let g:airline#extensions#tabline#formatter = 'unique_tail'

"general setting
set number
set relativenumber
set ai
set t_Co=256
set tabstop=4
set mouse=a
set shiftwidth=4
set encoding=utf8
set bs=2
set ruler
set laststatus=2
set cmdheight=2
set clipboard=unnamedplus
set guifont=Hack:h20
set showcmd

"keybinds
inoremap ( ()<Esc>i
inoremap " ""<Esc>i
inoremap [ []<Esc>i
inoremap ' ''<Esc>i
inoremap { {<CR>}<Esc>ko
inoremap } {}<Esc>i
inoremap <C-f> <Esc>:NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeToggle<CR>

"select all&copy paste
vmap <C-c> "+y
inoremap <C-v> <Esc>p
nnoremap <C-v> p
nnoremap <C-a> ggvG$

"tab navigation
nnoremap <tab> gt
nnoremap <S-tab> gT
inoremap <C-t> <Esc>:vnew<CR>:Startify<CR>
nnoremap <C-t> :vnew<CR>:Startify<CR>
inoremap <C-n> <Esc>:tabnew<CR>:Startify<CR>
nnoremap <C-n> :tabnew<CR>:Startify<CR>

" Compile and run
inoremap <F9> <Esc>:w<CR>:!~/runcpp.sh %:p:t %:p:h<CR>
nnoremap <F9> :w<CR>:!~/runcpp.sh %:p:t %:p:h<CR>

"theme
syntax on
"ayu gruvbox one codeblocks_dark monokai-chris monokai-phoenix neon neodark py-darcula spacegray vim-material void
colorscheme vim-material
set filetype=cpp
set background=dark
hi Normal ctermfg=white ctermbg=black

"cursor settings
"&t_SI for insertmode
"&t_EI for others
" Using iTerm5? Go-to preferences / profile / colors and disable the smart bar
" cursor color. Then pick a cursor and highlight color that matches your theme.
" That will ensure your cursor is always visible within insert mode.
"
" Reference chart of values:
"   Ps = 0  -> blinking block.
"   Ps = 1  -> blinking block (default).
"   Ps = 2  -> steady block.
"   Ps = 3  -> blinking underline.
"   Ps = 4  -> steady underline.
"   Ps = 5  -> blinking bar (xterm).
"   Ps = 6  -> steady bar (xterm).
let &t_SI="\e[2 q"
let &t_EI="\e[2 q"
