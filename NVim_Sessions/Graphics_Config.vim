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
badd +40 Platform/Private/Platform_SDL/Public/SDL3_window.cpp
badd +1 Platform/Private/Platform_SDL/Public/SDL3_libraries.h
badd +23 Platform/Private/Platform_SDL/Public/SDL3_WindowDefinitions.h
badd +17 Platform/Private/Platform_SDL/Private/Linux/SDL3_WindowDef_Linux.cpp
badd +38 Platform/CMakeLists.txt
badd +234 term://~/CPP_proyects/Engine_Test//49351:/usr/bin/bash
badd +11 Graphics/Private/RHI_Settings_Linux/RHI_Factory_Linux.cpp
badd +36 Platform/Private/Platform_SDL/Public/SDL3_WindowDefinitions.cpp
badd +29 brii_CORE/Settings/Settings_WindowEngine.h
badd +1 brii_CORE/Settings/Settings_UiEngine.h
badd +37 brii_CORE/Settings/Settings_BriiEngine.h
badd +21 brii_CORE/Application_Engine/Public/Application.h
badd +39 Platform/Public/Platform_Brii/Platform_Window.h
badd +57 brii_CORE/dataManager/dataTypes_brii.h
badd +37 brii_CORE/dataManager/convertion_DataManager.h
badd +19 brii_CORE/dataManager/algorithms_brii.h
badd +1 brii_CORE/dataManager/convertion_DataManager.cpp
badd +27 brii_CORE/dataManager/dataTypes_brii.cpp
badd +29 brii_CORE/files_CoreManager/files_Core.h
badd +233 build/release/_deps/sdl3-src/include/SDL3/SDL_video.h
badd +23 brii_CORE/Application_Engine/Private/Application_PC.cpp
badd +47 brii_COOKER/manager_briiCooker.h
badd +22 brii_COOKER/manager_briiCooker.cpp
badd +125 brii_CORE/model_binFormat.h
badd +1 ~/CPP_proyects/Engine_Test
badd +17 brii_CORE/dataManager/containerTypes_manager.h
badd +58 learningOpenGL/optimize_Algorithmics/optimizeAlgorithmics.h
badd +49 brii_CORE/String/stringID_brii.h
badd +70 brii_CORE/String/stringID_brii.cpp
badd +32 learningOpenGL/learningOpenGL.h
badd +32 learningOpenGL/CMakeLists.txt
badd +7 Platform/Private/FileSystem_OS/FileSystem_POSIX.cpp
badd +33 Platform/Public/Platform_Brii/Platform_FileSystem.h
badd +3 brii_CORE/material_binFormat.h
badd +13 brii_CORE/systemManager/platform_Manager.h
badd +1 Platform/Public/Platform_Brii/Platform_Input.h
badd +90 Platform/Private/FileSystem_OS/Linux/FileSystem_POSIX.cpp
badd +225 brii_CORE/mesh_binFormat.h
badd +42 brii_CORE/Settings/Settings_FileSystem.h
badd +1 brii_CORE/texturesPack_binFormat.h
badd +1 assets_engine/Localization/English_Lenguage/Window_EngineBrii/Principal_Window.csv
badd +62 CMakeLists.txt
badd +29 brii_CORE/CMakeLists.txt
badd +1 brii_CORE/main_core.h
badd +1 brii_COOKER/main_Cooker.cpp
badd +1 brii_COOKER/dataCooker.h
badd +1 learningOpenGL/STB_IMAGE_IMPLEMENT.cpp
badd +15 brii_COOKER/CMakeLists.txt
badd +38 Graphics/CMakeLists.txt
badd +17 Platform/Private/FileSystem_OS/standardLib/FileSystem_SCPP.cpp
badd +495 /usr/include/c++/16/bits/ios_base.h
badd +52 /usr/include/bits/fcntl-linux.h
badd +1 brii_CORE/dataManager/containerTypes_manager.cpp
badd +149 /usr/include/bits/types.h
badd +37 /usr/include/bits/typesizes.h
badd +160 /usr/include/sys/stat.h
badd +20 brii_CORE/Localization/LocalizationString_brii.h
badd +36 Graphics/Public/Graphics_Interface/IGraphics_brii.h
badd +32 brii_CORE/systemManager/logger.h
badd +22 brii_CORE/systemManager/logger.cpp
badd +42 Platform/Public/Platform_Brii/Platform_Log.h
badd +49 brii_CORE/Settings/Settings_LogEngine.h
badd +1 brii_CORE/dataManager/algorithms_brii.cpp
badd +1 Platform/Private/Platform_SDL/Public/SDL3_Input.cpp
badd +8 Graphics/Public/Graphics_Interface/IGraphics_brii.cpp
badd +490 /usr/include/c++/16/bits/unique_ptr.h
badd +1 Graphics/Public/RHI_Settings/RHI_Factory.h
badd +18 Graphics/Private/IG_OpenGL/IGraphics_OpenGL.cpp
badd +118 learningOpenGL/learningOpenGL.cpp
badd +1 learningOpenGL/main_EngineBrii/Private/main_SDL.cpp
badd +25 Platform/Public/Platform_Brii/Log_System/Platform_logCalls.h
badd +60 Platform/Public/Platform_Brii/Log_System/Platform_Log.h
badd +11 Platform/Private/Platform_Log/generic_LogCalls.cpp
badd +265 term://~/CPP_proyects/Engine_Test//17298:/usr/bin/bash
badd +254 term://~/CPP_proyects/Engine_Test//24704:/usr/bin/bash
badd +73 Platform/Private/Platform_Log/Linux/linux_LogCalls.cpp
badd +8 Platform/Public/Platform_Brii/Platform_IOS.h
badd +10 Platform/Private/Platform_Iostream/linux_IOS.cpp
badd +27 brii_CORE/String/BriiType_string.h
badd +30 brii_CORE/String/BriiType_string.cpp
badd +862 /usr/include/c++/16/string_view
badd +79 /usr/include/c++/16/bits/stringfwd.h
badd +365 /usr/include/c++/16/bits/basic_string.h
badd +54 Platform/Private/Platform_Log/Linux/linux_Log.cpp
badd +25 brii_CORE/Settings/Settings_locString.h
badd +17 brii_CORE/Localization/LocalizationString_brii.cpp
badd +12 brii_CORE/Directories_and_Files/Private/DirAndFile_Manager.cpp
badd +20 brii_CORE/Directories_and_Files/Public/FilesAssets_brii.h
badd +7 brii_CORE/Directories_and_Files/Public/DirAssets_brii.h
badd +10 brii_CORE/Directories_and_Files/Public/DirAndFile_Manager.h
badd +15 brii_CORE/dataManager/Public/portability_variables.h
badd +4 brii_CORE/dataManager/Private/portability_variables.cpp
argglobal
%argdel
$argadd ~/CPP_proyects/Engine_Test
edit brii_CORE/Directories_and_Files/Private/DirAndFile_Manager.cpp
argglobal
balt brii_CORE/Directories_and_Files/Public/DirAndFile_Manager.h
setlocal foldmethod=manual
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=99
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
sil! 2,4fold
sil! 12,21fold
sil! 9,22fold
let &fdl = &fdl
let s:l = 22 - ((21 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 22
normal! 0
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
