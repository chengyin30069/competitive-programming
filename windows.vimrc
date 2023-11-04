call plug#begin()

Plug 'scrooloose/nerdtree'

Plug 'tpope/vim-commentary'

Plug 'mhinz/vim-startify'

Plug 'vim-airline/vim-airline'

Plug 'vim-airline/vim-airline-themes'

Plug 'flazz/vim-colorschemes'

call plug#end()

let g:airline#extensions#tabline#enabled = 1

let g:airline_theme='solarized'

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
set guifont=Hack:h16
set showcmd
set guioptions -=m 
set guioptions -=T
set belloff=all
set autoread
" set nowrap
filetype indent on
au GUIEnter * sim ~x

"keybinds
inoremap ( ()<Esc>i
inoremap " ""<Esc>i
inoremap [ []<Esc>i
inoremap ' ''<Esc>i
inoremap { {<CR>}<Esc>ko
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
nnoremap <C-r> ggvG$d:r template.cpp<CR>:w<CR>

" Compile and run
inoremap <F9> <Esc>:w<CR>:!g++ -O0 -std=c++17 -Wall -Wextra -Dlocal % -o out && out<CR>
nnoremap <F9> :w<CR>:!g++ -O0 -std=c++17 -Wall -Wextra -Dlocal % -o out && out<CR>

"theme
syntax on
"ayu gruvbox one codeblocks_dark monokai-chris monokai-phoenix neon neodark py-darcula spacegray vim-material void
colorscheme ayu
set filetype=cpp
set background=dark
hi Normal ctermfg=white ctermbg=black
