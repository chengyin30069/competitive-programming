call plug#begin()

Plug 'scrooloose/nerdtree'

Plug 'tpope/vim-commentary'

Plug 'mhinz/vim-startify'

Plug 'vim-airline/vim-airline'

Plug 'vim-airline/vim-airline-themes'

Plug 'flazz/vim-colorschemes'

call plug#end()

let g:airline#extensions#tabline#enabled = 1

let g:airline_theme='wombat'

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
set guifont=Hack:h17
set showcmd

"keybinds
inoremap ( ()<Esc>i
inoremap " ""<Esc>i
inoremap [ []<Esc>i
inoremap ' ''<Esc>i
inoremap { {<CR>}<Esc>ko
inoremap } {}<Esc>i
inoremap <C-s> <Esc>:w<CR>
nnoremap <C-s> :w<CR>
inoremap <C-w> <Esc>:wq<CR>
nnoremap <C-w> :wq<CR>
inoremap <C-q> <Esc>:q<CR>
nnoremap <C-q> :q<CR>
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

"gaming arrow keys
nnoremap w k
nnoremap a h
nnoremap s j
nnoremap d l
vnoremap w k
vnoremap a h
vnoremap s j
vnoremap d l

" Compile and run
inoremap <C-b> <Esc>:w<CR>:!g++ -O0 -std=c++17 -Wall -Wextra -Dlocal % -o out && out<CR>
nnoremap <C-b> :w<CR>:!g++ -O0 -std=c++17 -Wall -Wextra -Dlocal % -o out && out<CR>

"theme
syntax on
colorscheme one
set filetype=cpp
set background=dark
hi Normal ctermfg=white ctermbg=black
