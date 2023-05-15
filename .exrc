let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <expr> <PageUp> coc#pum#visible() ? coc#pum#scroll(0) : "\<PageUp>"
inoremap <silent> <expr> <PageDown> coc#pum#visible() ? coc#pum#scroll(1) : "\<PageDown>"
inoremap <silent> <expr> <C-Y> coc#pum#visible() ? coc#pum#confirm() : "\"
inoremap <silent> <expr> <C-E> coc#pum#visible() ? coc#pum#cancel() : "\"
inoremap <silent> <expr> <Up> coc#pum#visible() ? coc#pum#prev(0) : "\<Up>"
inoremap <silent> <expr> <Down> coc#pum#visible() ? coc#pum#next(0) : "\<Down>"
inoremap <silent> <expr> <C-P> coc#pum#visible() ? coc#pum#prev(1) : "\"
inoremap <silent> <expr> <C-N> coc#pum#visible() ? coc#pum#next(1) : "\"
imap <C-G>S <Plug>ISurround
imap <C-G>s <Plug>Isurround
imap <C-S> <Plug>Isurround
inoremap <C-W> u
inoremap <C-U> u
nnoremap  :NERDTreeFocus
snoremap <silent>  c
nnoremap  :call CocActionAsync('jumpDefinition')
xnoremap <silent>  :call multiple_cursors#new("v", 0)
nnoremap <silent>  :call multiple_cursors#new("n", 1)
snoremap  "_c
nnoremap  :NERDTreeToggle
xnoremap # y?\V"
omap <silent> % <Plug>(MatchitOperationForward)
xmap <silent> % <Plug>(MatchitVisualForward)
nmap <silent> % <Plug>(MatchitNormalForward)
nnoremap & :&&
xnoremap * y/\V"
xmap S <Plug>VSurround
nnoremap Y y$
omap <silent> [% <Plug>(MatchitOperationMultiBackward)
xmap <silent> [% <Plug>(MatchitVisualMultiBackward)
nmap <silent> [% <Plug>(MatchitNormalMultiBackward)
nmap \w\m <Plug>VimwikiMakeTomorrowDiaryNote
nmap \w\y <Plug>VimwikiMakeYesterdayDiaryNote
nmap \w\t <Plug>VimwikiTabMakeDiaryNote
nmap \w\w <Plug>VimwikiMakeDiaryNote
nmap \w\i <Plug>VimwikiDiaryGenerateLinks
nmap \wi <Plug>VimwikiDiaryIndex
nmap \ws <Plug>VimwikiUISelect
nmap \wt <Plug>VimwikiTabIndex
nmap \ww <Plug>VimwikiIndex
omap <silent> ]% <Plug>(MatchitOperationMultiForward)
xmap <silent> ]% <Plug>(MatchitVisualMultiForward)
nmap <silent> ]% <Plug>(MatchitNormalMultiForward)
xmap a% <Plug>(MatchitVisualTextObject)
nmap cS <Plug>CSurround
nmap cs <Plug>Csurround
nmap ds <Plug>Dsurround
xmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
omap <silent> g% <Plug>(MatchitOperationBackward)
xmap <silent> g% <Plug>(MatchitVisualBackward)
nmap <silent> g% <Plug>(MatchitNormalBackward)
xnoremap <silent> g<M-n> :call multiple_cursors#select_all("v", 0)
nnoremap <silent> g<M-n> :call multiple_cursors#select_all("n", 0)
xnoremap <silent> g<C-N> :call multiple_cursors#new("v", 0)
xnoremap <silent> g :call multiple_cursors#new("v", 0)
nnoremap <silent> g<C-N> :call multiple_cursors#new("n", 0)
nnoremap <silent> g :call multiple_cursors#new("n", 0)
nmap gcu <Plug>Commentary<Plug>Commentary
nmap gcc <Plug>CommentaryLine
omap gc <Plug>Commentary
nmap gc <Plug>Commentary
xmap gc <Plug>Commentary
xmap gS <Plug>VgSurround
nmap ySS <Plug>YSsurround
nmap ySs <Plug>YSsurround
nmap yss <Plug>Yssurround
nmap yS <Plug>YSurround
nmap ys <Plug>Ysurround
snoremap <C-R> "_c
snoremap <silent> <C-H> c
snoremap <silent> <Del> c
snoremap <silent> <BS> c
xnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
xmap <silent> <Plug>(MatchitVisualTextObject) <Plug>(MatchitVisualMultiBackward)o<Plug>(MatchitVisualMultiForward)
onoremap <silent> <Plug>(MatchitOperationMultiForward) :call matchit#MultiMatch("W",  "o")
onoremap <silent> <Plug>(MatchitOperationMultiBackward) :call matchit#MultiMatch("bW", "o")
xnoremap <silent> <Plug>(MatchitVisualMultiForward) :call matchit#MultiMatch("W",  "n")m'gv``
xnoremap <silent> <Plug>(MatchitVisualMultiBackward) :call matchit#MultiMatch("bW", "n")m'gv``
nnoremap <silent> <Plug>(MatchitNormalMultiForward) :call matchit#MultiMatch("W",  "n")
nnoremap <silent> <Plug>(MatchitNormalMultiBackward) :call matchit#MultiMatch("bW", "n")
onoremap <silent> <Plug>(MatchitOperationBackward) :call matchit#Match_wrapper('',0,'o')
onoremap <silent> <Plug>(MatchitOperationForward) :call matchit#Match_wrapper('',1,'o')
xnoremap <silent> <Plug>(MatchitVisualBackward) :call matchit#Match_wrapper('',0,'v')m'gv``
xnoremap <silent> <Plug>(MatchitVisualForward) :call matchit#Match_wrapper('',1,'v'):if col("''") != col("$") | exe ":normal! m'" | endifgv``
nnoremap <silent> <Plug>(MatchitNormalBackward) :call matchit#Match_wrapper('',0,'n')
nnoremap <silent> <Plug>(MatchitNormalForward) :call matchit#Match_wrapper('',1,'n')
xnoremap <silent> <M-n> :call multiple_cursors#select_all("v", 0)
nnoremap <silent> <M-n> :call multiple_cursors#select_all("n", 1)
xnoremap <silent> <C-N> :call multiple_cursors#new("v", 0)
nnoremap <silent> <F11> :call vimterm_term#exec_file()
onoremap <silent> <Plug>(coc-classobj-a) :call CocAction('selectSymbolRange', v:false, '', ['Interface', 'Struct', 'Class'])
onoremap <silent> <Plug>(coc-classobj-i) :call CocAction('selectSymbolRange', v:true, '', ['Interface', 'Struct', 'Class'])
vnoremap <silent> <Plug>(coc-classobj-a) :call CocAction('selectSymbolRange', v:false, visualmode(), ['Interface', 'Struct', 'Class'])
vnoremap <silent> <Plug>(coc-classobj-i) :call CocAction('selectSymbolRange', v:true, visualmode(), ['Interface', 'Struct', 'Class'])
onoremap <silent> <Plug>(coc-funcobj-a) :call CocAction('selectSymbolRange', v:false, '', ['Method', 'Function'])
onoremap <silent> <Plug>(coc-funcobj-i) :call CocAction('selectSymbolRange', v:true, '', ['Method', 'Function'])
vnoremap <silent> <Plug>(coc-funcobj-a) :call CocAction('selectSymbolRange', v:false, visualmode(), ['Method', 'Function'])
vnoremap <silent> <Plug>(coc-funcobj-i) :call CocAction('selectSymbolRange', v:true, visualmode(), ['Method', 'Function'])
nnoremap <silent> <Plug>(coc-cursors-position) :call CocAction('cursorsSelect', bufnr('%'), 'position', 'n')
nnoremap <silent> <Plug>(coc-cursors-word) :call CocAction('cursorsSelect', bufnr('%'), 'word', 'n')
vnoremap <silent> <Plug>(coc-cursors-range) :call CocAction('cursorsSelect', bufnr('%'), 'range', visualmode())
nnoremap <silent> <Plug>(coc-refactor) :call       CocActionAsync('refactor')
nnoremap <silent> <Plug>(coc-command-repeat) :call       CocAction('repeatCommand')
nnoremap <silent> <Plug>(coc-float-jump) :call       coc#float#jump()
nnoremap <silent> <Plug>(coc-float-hide) :call       coc#float#close_all()
nnoremap <silent> <Plug>(coc-fix-current) :call       CocActionAsync('doQuickfix')
nnoremap <silent> <Plug>(coc-openlink) :call       CocActionAsync('openLink')
nnoremap <silent> <Plug>(coc-references-used) :call       CocActionAsync('jumpUsed')
nnoremap <silent> <Plug>(coc-references) :call       CocActionAsync('jumpReferences')
nnoremap <silent> <Plug>(coc-type-definition) :call       CocActionAsync('jumpTypeDefinition')
nnoremap <silent> <Plug>(coc-implementation) :call       CocActionAsync('jumpImplementation')
nnoremap <silent> <Plug>(coc-declaration) :call       CocActionAsync('jumpDeclaration')
nnoremap <silent> <Plug>(coc-definition) :call       CocActionAsync('jumpDefinition')
nnoremap <silent> <Plug>(coc-diagnostic-prev-error) :call       CocActionAsync('diagnosticPrevious', 'error')
nnoremap <silent> <Plug>(coc-diagnostic-next-error) :call       CocActionAsync('diagnosticNext',     'error')
nnoremap <silent> <Plug>(coc-diagnostic-prev) :call       CocActionAsync('diagnosticPrevious')
nnoremap <silent> <Plug>(coc-diagnostic-next) :call       CocActionAsync('diagnosticNext')
nnoremap <silent> <Plug>(coc-diagnostic-info) :call       CocActionAsync('diagnosticInfo')
nnoremap <silent> <Plug>(coc-format) :call       CocActionAsync('format')
nnoremap <silent> <Plug>(coc-rename) :call       CocActionAsync('rename')
nnoremap <Plug>(coc-codeaction-source) :call       CocActionAsync('codeAction', '', ['source'], v:true)
nnoremap <Plug>(coc-codeaction-refactor) :call       CocActionAsync('codeAction', 'cursor', ['refactor'], v:true)
nnoremap <Plug>(coc-codeaction-cursor) :call       CocActionAsync('codeAction', 'cursor')
nnoremap <Plug>(coc-codeaction-line) :call       CocActionAsync('codeAction', 'currline')
nnoremap <Plug>(coc-codeaction) :call       CocActionAsync('codeAction', '')
vnoremap <Plug>(coc-codeaction-refactor-selected) :call       CocActionAsync('codeAction', visualmode(), ['refactor'], v:true)
vnoremap <silent> <Plug>(coc-codeaction-selected) :call       CocActionAsync('codeAction', visualmode())
vnoremap <silent> <Plug>(coc-format-selected) :call       CocActionAsync('formatSelected', visualmode())
nnoremap <Plug>(coc-codelens-action) :call       CocActionAsync('codeLensAction')
nnoremap <Plug>(coc-range-select) :call       CocActionAsync('rangeSelect',     '', v:true)
vnoremap <silent> <Plug>(coc-range-select-backward) :call       CocActionAsync('rangeSelect',     visualmode(), v:false)
vnoremap <silent> <Plug>(coc-range-select) :call       CocActionAsync('rangeSelect',     visualmode(), v:true)
nmap <silent> <Plug>CommentaryUndo :echoerr "Change your <Plug>CommentaryUndo map to <Plug>Commentary<Plug>Commentary"
nnoremap <silent> <Plug>SurroundRepeat .
nmap <F8> :TagbarToggle
nnoremap <C-T> :NERDTreeToggle
nnoremap <silent> <C-N> :call multiple_cursors#new("n", 1)
nnoremap <C-F> :NERDTreeFocus
nnoremap <C-L> :call CocActionAsync('jumpDefinition')
inoremap <silent> <expr>  coc#pum#visible() ? coc#pum#cancel() : "\"
imap S <Plug>ISurround
imap s <Plug>Isurround
inoremap <nowait> <silent> <expr> 	 coc#pum#visible() ? coc#_select_confirm() : "	"
inoremap <silent> <expr>  coc#pum#visible() ? coc#pum#next(1) : "\"
inoremap <silent> <expr>  coc#pum#visible() ? coc#pum#prev(1) : "\"
imap  <Plug>Isurround
inoremap  u
inoremap  u
inoremap <silent> <expr>  coc#pum#visible() ? coc#pum#confirm() : "\"
let &cpo=s:cpo_save
unlet s:cpo_save
set completeopt=menu
set helplang=en
set mouse=a
set runtimepath=~/.config/nvim,~/.local/share/nvim/plugged/vim-surround,~/.local/share/nvim/plugged/nerdtree,~/.local/share/nvim/plugged/vim-commentary,~/.local/share/nvim/plugged/vim-airline,~/.local/share/nvim/plugged/pgsql.vim,~/.local/share/nvim/plugged/vim-css-color,~/.local/share/nvim/plugged/awesome-vim-colorschemes,~/.local/share/nvim/plugged/coc.nvim,~/.local/share/nvim/plugged/vim-devicons,~/.local/share/nvim/plugged/vim-terminal,~/.local/share/nvim/plugged/tagbar,~/.local/share/nvim/plugged/vim-multiple-cursors,~/.local/share/nvim/plugged/nvim-gdscript3,~/.local/share/nvim/plugged/vimdiscord,~/.local/share/nvim/plugged/vimwiki,/etc/xdg/nvim,~/.local/share/nvim/site,~/.local/share/flatpak/exports/share/nvim/site,/var/lib/flatpak/exports/share/nvim/site,/usr/local/share/nvim/site,/usr/share/nvim/site,/usr/share/nvim/runtime,/usr/share/nvim/runtime/pack/dist/opt/matchit,/usr/lib/nvim,/usr/share/nvim/site/after,/usr/local/share/nvim/site/after,/var/lib/flatpak/exports/share/nvim/site/after,~/.local/share/flatpak/exports/share/nvim/site/after,~/.local/share/nvim/site/after,/etc/xdg/nvim/after,~/.config/nvim/after,~/.local/share/nvim/plugged/vim-css-color/after,~/.local/share/nvim/plugged/awesome-vim-colorschemes/after,/usr/share/vim/vimfiles/
set shiftwidth=4
set softtabstop=4
set tabstop=4
set window=62
" vim: set ft=vim :
