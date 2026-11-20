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
badd +92 Platform/Private/Thread_OS/Thread_POSIX.cpp
badd +42 Platform/Public/Platform_Brii/Platform_Thread.h
badd +1 Platform/Public/Platform_Brii/Platform_Input.h
badd +95 Platform/Public/Platform_Brii/Platform_FileSystem.h
badd +25 Platform/Public/CoreSystems_Brii/Job_Schedule.h
badd +1 brii_CORE/CMakeLists.txt
badd +37 brii_CORE/Settings/Settings_Time.h
badd +11 brii_CORE/Settings/Settings_JobSystem.h
badd +28 brii_CORE/Settings/Settings_FileSystem.h
badd +42 brii_CORE/Settings/Settings_WindowEngine.h
badd +19 brii_CORE/Settings/Settings_Thread.h
badd +1 brii_CORE/Settings/Settings_UiEngine.h
badd +11 brii_CORE/Application_Engine/Private/Application_PC.cpp
badd +55 brii_CORE/Application_Engine/Public/Application.h
badd +18 brii_CORE/Directories_and_Files/Public/DirAndFiles_info.h
badd +31 brii_CORE/Directories_and_Files/Public/FilesAssets_brii.h
badd +1 brii_CORE/Directories_and_Files/Public/DirAndFile_Manager.h
badd +44 brii_CORE/Settings/Settings_locString.h
badd +11 Platform/Private/CoreSystems_OS/Job_Schedule/Job_Shedule_Linux.cpp
badd +1 Platform/Private/CoreSystems_OS/Job_Schedule/Job_Schedule_generalBrii.cpp
badd +73 Platform/Private/Platform_Log/Linux/linux_Log.cpp
badd +43 Platform/Public/Platform_Brii/Log_System/Platform_Log.h
badd +73 Platform/Public/Platform_Brii/Log_System/Platform_logCalls.h
badd +57 brii_CORE/Settings/Settings_LogEngine.h
badd +16 brii_CORE/Settings/Settings_BriiEngine.h
badd +43 brii_CORE/dataManager/dataTypes_brii.h
badd +1 brii_CORE/dataManager/dataTypes_brii.cpp
badd +31 Platform/Private/FileSystem_OS/Linux/FileSystem_POSIX.cpp
badd +17 brii_CORE/Directories_and_Files/Private/DirAndFile_Manager.cpp
badd +95 brii_CORE/String/BriiType_string.h
badd +52 brii_CORE/String/stringID_brii.h
badd +76 brii_CORE/String/stringID_brii.cpp
badd +892 /usr/include/c++/16/bits/chrono.h
badd +143 /usr/include/c++/16/type_traits
badd +272 /usr/include/pthread.h
badd +155 brii_CORE/String/BriiType_string.cpp
badd +15 Platform/Public/Platform_Brii/Platform_Types.h
badd +4918 /usr/lib/clang/23/include/emmintrin.h
badd +68 /usr/include/sched.h
badd +21 /usr/include/bits/types/struct_timespec.h
badd +200 /usr/include/bits/types.h
badd +18 learningOpenGL/learningOpenGL.h
badd +58 learningOpenGL/learningOpenGL.cpp
badd +84 Platform/Public/Platform_Brii/Platform_Window.h
badd +102 Platform/Private/Platform_SDL/Public/SDL3_window.cpp
badd +38 Graphics/Public/Graphics_Interface/IGraphics_brii.h
badd +18 Graphics/Private/IG_OpenGL/IGraphics_OpenGL.h
badd +16 Graphics/Private/IG_OpenGL/IGraphics_OpenGL.cpp
badd +4 Graphics/Public/Graphics_Interface/IGraphics_brii.cpp
badd +7 Platform/Private/Platform_SDL/Private/Linux/SDL3_WindowDef_Linux.cpp
badd +1 Platform/Private/Platform_SDL/Public/SDL3_libraries.h
badd +43 brii_CORE/systemManager/logger.h
badd +1 Platform/Public/Platform_Brii/Platform_IOS.h
badd +10 Platform/Public/Platform_Brii/Platform_Engine.h
badd +21 Platform/Private/Platform_SDL/Public/SDL3_WindowDefinitions.h
badd +6 Platform/Private/Platform_SDL/Public/SDL3_WindowDefinitions.cpp
badd +15 Graphics/Private/RHI_Settings_Linux/RHI_Factory_Linux.cpp
badd +14 Graphics/Public/RHI_Settings/RHI_Factory.h
badd +1 Platform/CMakeLists.txt
badd +1 Platform/Private/Platform_SDL/Public/SDL3_Input.cpp
badd +85 brii_CORE/Localization/LocalizationString_brii.h
badd +26 brii_CORE/Localization/Public/SourceLocation_brii.h
badd +1 brii_CORE/Localization/Private/SourceLocation_brii.cpp
badd +30 brii_CORE/Localization/LocalizationString_brii.cpp
argglobal
%argdel
$argadd ~/CPP_proyects/Engine_Test/
edit Platform/Public/Platform_Brii/Platform_Window.h
argglobal
balt brii_CORE/Localization/LocalizationString_brii.h
setlocal foldmethod=manual
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=99
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
sil! 3,4fold
sil! 6,22fold
sil! 31,39fold
sil! 42,57fold
sil! 65,81fold
sil! 26,82fold
let &fdl = &fdl
let s:l = 84 - ((26 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 84
normal! 047|
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
