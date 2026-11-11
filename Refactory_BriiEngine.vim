let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
doautoall SessionLoadPre
silent only
silent tabonly
cd ~/CPP_proyects/Engine_Test
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
set shortmess+=aoO
badd +54 Platform/Private/Platform_Log/Linux/linux_LogCalls.cpp
badd +250 Platform/Private/Thread_OS/Thread_POSIX.cpp
badd +41 Platform/Public/Platform_Brii/Platform_Thread.h
badd +1 Platform/Public/Platform_Brii/Platform_Input.h
badd +33 Platform/Public/Platform_Brii/Platform_FileSystem.h
badd +24 Platform/Public/CoreSystems_Brii/Job_Schedule.h
badd +0 ~/CPP_proyects/Engine_Test
badd +1 brii_CORE/CMakeLists.txt
badd +34 brii_CORE/Settings/Settings_Time.h
badd +14 brii_CORE/Settings/Settings_JobSystem.h
badd +28 brii_CORE/Settings/Settings_FileSystem.h
badd +21 brii_CORE/Settings/Settings_WindowEngine.h
badd +26 brii_CORE/Settings/Settings_Thread.h
badd +1 brii_CORE/Settings/Settings_UiEngine.h
badd +20 brii_CORE/Application_Engine/Private/Application_PC.cpp
badd +37 brii_CORE/Application_Engine/Public/Application.h
badd +1 brii_CORE/Directories_and_Files/Public/DirAndFiles_info.h
badd +14 brii_CORE/Directories_and_Files/Public/FilesAssets_brii.h
badd +1 brii_CORE/Directories_and_Files/Public/DirAndFile_Manager.h
badd +38 brii_CORE/Settings/Settings_locString.h
badd +1 Platform/Private/CoreSystems_OS/Job_Schedule/Job_Shedule_Linux.cpp
badd +1 Platform/Private/CoreSystems_OS/Job_Schedule/Job_Schedule_generalBrii.cpp
badd +73 Platform/Private/Platform_Log/Linux/linux_Log.cpp
badd +43 Platform/Public/Platform_Brii/Log_System/Platform_Log.h
badd +73 Platform/Public/Platform_Brii/Log_System/Platform_logCalls.h
badd +73 brii_CORE/Settings/Settings_LogEngine.h
badd +50 brii_CORE/Settings/Settings_BriiEngine.h
badd +82 brii_CORE/dataManager/dataTypes_brii.h
badd +1 brii_CORE/dataManager/dataTypes_brii.cpp
badd +31 Platform/Private/FileSystem_OS/Linux/FileSystem_POSIX.cpp
badd +17 brii_CORE/Directories_and_Files/Private/DirAndFile_Manager.cpp
badd +95 brii_CORE/String/BriiType_string.h
badd +52 brii_CORE/String/stringID_brii.h
badd +76 brii_CORE/String/stringID_brii.cpp
badd +295 /usr/include/c++/16/bits/chrono.h
badd +143 /usr/include/c++/16/type_traits
badd +272 /usr/include/pthread.h
badd +155 brii_CORE/String/BriiType_string.cpp
argglobal
%argdel
$argadd ~/CPP_proyects/Engine_Test
edit Platform/Private/Thread_OS/Thread_POSIX.cpp
argglobal
balt Platform/Public/Platform_Brii/Platform_Thread.h
setlocal foldmethod=manual
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=99
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
sil! 2,8fold
sil! 10,18fold
sil! 23,34fold
sil! 20,36fold
sil! 42,45fold
sil! 47,50fold
sil! 52,55fold
sil! 57,61fold
sil! 63,67fold
sil! 40,68fold
sil! 38,70fold
sil! 37,70fold
sil! 75,86fold
sil! 72,89fold
sil! 71,89fold
sil! 94,99fold
sil! 102,107fold
sil! 115,120fold
sil! 123,128fold
sil! 130,135fold
sil! 91,139fold
sil! 143,148fold
sil! 152,155fold
sil! 150,161fold
sil! 173,176fold
sil! 178,183fold
sil! 190,193fold
sil! 185,193fold
sil! 165,196fold
sil! 163,199fold
sil! 201,204fold
sil! 208,212fold
sil! 215,218fold
sil! 206,223fold
sil! 227,231fold
sil! 233,236fold
sil! 225,237fold
sil! 248,251fold
sil! 252,255fold
sil! 257,266fold
sil! 268,271fold
sil! 277,282fold
sil! 273,285fold
sil! 245,287fold
let &fdl = &fdl
37
sil! normal! zo
37
sil! normal! zc
71
sil! normal! zo
71
sil! normal! zc
let s:l = 243 - ((23 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 243
normal! 048|
lcd ~/CPP_proyects/Engine_Test
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
