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
badd +320 Platform/Private/Thread_OS/Thread_POSIX.cpp
badd +27 Platform/Public/Platform_Brii/Platform_Thread.h
badd +1 Platform/Public/Platform_Brii/Platform_Input.h
badd +86 Platform/Public/Platform_Brii/Platform_FileSystem.h
badd +25 Platform/Public/CoreSystems_Brii/Job_Schedule.h
badd +77 brii_CORE/CMakeLists.txt
badd +37 brii_CORE/Settings/Settings_Time.h
badd +11 brii_CORE/Settings/Settings_JobSystem.h
badd +28 brii_CORE/Settings/Settings_FileSystem.h
badd +44 brii_CORE/Settings/Settings_WindowEngine.h
badd +19 brii_CORE/Settings/Settings_Thread.h
badd +1 brii_CORE/Settings/Settings_UiEngine.h
badd +8 brii_CORE/Application_Engine/Private/Application_PC.cpp
badd +21 brii_CORE/Application_Engine/Public/Application.h
badd +18 brii_CORE/Directories_and_Files/Public/DirAndFiles_info.h
badd +31 brii_CORE/Directories_and_Files/Public/FilesAssets_brii.h
badd +1 brii_CORE/Directories_and_Files/Public/DirAndFile_Manager.h
badd +22 brii_CORE/Settings/Settings_locString.h
badd +11 Platform/Private/CoreSystems_OS/Job_Schedule/Job_Shedule_Linux.cpp
badd +1 Platform/Private/CoreSystems_OS/Job_Schedule/Job_Schedule_generalBrii.cpp
badd +73 Platform/Private/Platform_Log/Linux/linux_Log.cpp
badd +64 Platform/Public/Platform_Brii/Log_System/Platform_Log.h
badd +25 Platform/Public/Platform_Brii/Log_System/Platform_logCalls.h
badd +57 brii_CORE/Settings/Settings_LogEngine.h
badd +22 brii_CORE/Settings/Settings_BriiEngine.h
badd +19 brii_CORE/dataManager/dataTypes_brii.h
badd +1 brii_CORE/dataManager/dataTypes_brii.cpp
badd +31 Platform/Private/FileSystem_OS/Linux/FileSystem_POSIX.cpp
badd +17 brii_CORE/Directories_and_Files/Private/DirAndFile_Manager.cpp
badd +95 brii_CORE/String/BriiType_string.h
badd +3 brii_CORE/String/stringID_brii.h
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
badd +448 learningOpenGL/learningOpenGL.cpp
badd +44 Platform/Public/Platform_Brii/Platform_Window.h
badd +111 Platform/Private/Platform_SDL/Public/SDL3_window.cpp
badd +38 Graphics/Public/Graphics_Interface/IGraphics_brii.h
badd +18 Graphics/Private/IG_OpenGL/IGraphics_OpenGL.h
badd +16 Graphics/Private/IG_OpenGL/IGraphics_OpenGL.cpp
badd +4 Graphics/Public/Graphics_Interface/IGraphics_brii.cpp
badd +79 Platform/Private/Platform_SDL/Private/Linux/SDL3_WindowDef_Linux.cpp
badd +1 Platform/Private/Platform_SDL/Public/SDL3_libraries.h
badd +43 brii_CORE/systemManager/logger.h
badd +1 Platform/Public/Platform_Brii/Platform_IOS.h
badd +10 Platform/Public/Platform_Brii/Platform_Engine.h
badd +5 Platform/Private/Platform_SDL/Public/SDL3_WindowDefinitions.h
badd +6 Platform/Private/Platform_SDL/Public/SDL3_WindowDefinitions.cpp
badd +50 Graphics/Private/RHI_Settings_Linux/RHI_Factory_Linux.cpp
badd +29 Graphics/Public/RHI_Settings/RHI_Factory.h
badd +1 Platform/CMakeLists.txt
badd +1 Platform/Private/Platform_SDL/Public/SDL3_Input.cpp
badd +51 brii_CORE/Localization/LocalizationString_brii.h
badd +28 brii_CORE/Localization/Public/SourceLocation_brii.h
badd +1 brii_CORE/Localization/Private/SourceLocation_brii.cpp
badd +38 brii_CORE/Localization/LocalizationString_brii.cpp
badd +1 ~/CPP_proyects/Engine_Test
badd +29 brii_CORE/dataManager/uniquePtr/uniquePtrT_brii.h
badd +1 brii_CORE/dataManager/uniquePtr/uniquePtrT_brii.cpp
badd +679 build/release/_deps/sdl3-src/include/SDL3/SDL_video.h
badd +458 build/release/_deps/sdl3-src/src/dynapi/SDL_dynapi_overrides.h
badd +538 build/release/_deps/sdl3-src/src/dynapi/SDL_dynapi_procs.h
badd +20 brii_CORE/Localization/Public/LocStr_Calls.h
badd +32 brii_CORE/Localization/Private/LocStr_Calls.cpp
badd +0 neo-tree\ filesystem\ \[1]
argglobal
%argdel
$argadd ~/CPP_proyects/Engine_Test
edit Platform/Private/Platform_SDL/Public/SDL3_window.cpp
argglobal
balt Platform/Public/Platform_Brii/Platform_Window.h
setlocal foldmethod=manual
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=99
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
sil! 4,7fold
sil! 67,72fold
sil! 55,73fold
sil! 43,74fold
sil! 19,75fold
sil! 17,77fold
sil! 82,85fold
sil! 101,106fold
sil! 117,121fold
sil! 113,124fold
sil! 99,124fold
sil! 138,143fold
sil! 90,145fold
sil! 147,150fold
sil! 152,155fold
sil! 157,161fold
sil! 168,172fold
sil! 179,182fold
sil! 176,183fold
sil! 174,185fold
sil! 188,191fold
sil! 192,195fold
sil! 79,197fold
sil! 202,216fold
let &fdl = &fdl
let s:l = 111 - ((26 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 111
normal! 044|
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
