set nocp ai si nu et bs=2 mouse=a
set ts=4 sts=4 sw=4 hls showmatch
set ruler rulerformat=%17.(%l:%c%)
set noswapfile autoread wildmenu wildmode=list:longest
set number autoindent smartindent
syntax on

map <C-b> <ESC>:w<CR>:!gcc %:r.c -o %:r && ./%:r<CR>
