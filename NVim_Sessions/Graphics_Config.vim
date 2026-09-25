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
badd +23 Platform/CMakeLists.txt
badd +254 term://~/CPP_proyects/Engine_Test//42332:/usr/bin/bash
badd +11 Graphics/Private/RHI_Settings_Linux/RHI_Factory_Linux.cpp
badd +36 Platform/Private/Platform_SDL/Public/SDL3_WindowDefinitions.cpp
badd +29 brii_CORE/Settings/Settings_WindowEngine.h
badd +1 brii_CORE/Settings/Settings_UiEngine.h
badd +37 brii_CORE/Settings/Settings_BriiEngine.h
badd +21 brii_CORE/Application_Engine/Public/Application.h
badd +37 Platform/Public/Platform_Brii/Platform_Window.h
badd +60 brii_CORE/dataManager/dataTypes_brii.h
badd +37 brii_CORE/dataManager/convertion_DataManager.h
badd +19 brii_CORE/dataManager/algorithms_brii.h
badd +1 brii_CORE/dataManager/convertion_DataManager.cpp
badd +35 brii_CORE/dataManager/dataTypes_brii.cpp
badd +29 brii_CORE/files_CoreManager/files_Core.h
badd +233 build/release/_deps/sdl3-src/include/SDL3/SDL_video.h
badd +23 brii_CORE/Application_Engine/Private/Application_PC.cpp
badd +101 brii_COOKER/manager_briiCooker.h
badd +22 brii_COOKER/manager_briiCooker.cpp
badd +141 brii_CORE/model_binFormat.h
badd +1 ~/CPP_proyects/Engine_Test
badd +17 brii_CORE/dataManager/containerTypes_manager.h
badd +58 learningOpenGL/optimize_Algorithmics/optimizeAlgorithmics.h
badd +30 brii_CORE/String/stringID_brii.h
badd +48 brii_CORE/String/stringID_brii.cpp
badd +32 learningOpenGL/learningOpenGL.h
badd +32 learningOpenGL/CMakeLists.txt
badd +7 Platform/Private/FileSystem_OS/FileSystem_POSIX.cpp
badd +66 Platform/Public/Platform_Brii/Platform_FileSystem.h
badd +3 brii_CORE/material_binFormat.h
badd +13 brii_CORE/systemManager/platform_Manager.h
badd +1 Platform/Public/Platform_Brii/Platform_Input.h
badd +229 Platform/Private/FileSystem_OS/Linux/FileSystem_POSIX.cpp
badd +267 brii_CORE/mesh_binFormat.h
badd +37 brii_CORE/Settings/Settings_FileSystem.h
badd +1 brii_CORE/texturesPack_binFormat.h
badd +1 assets_engine/Localization/English_Lenguage/Window_EngineBrii/Principal_Window.csv
badd +201 CMakeLists.txt
badd +63 brii_CORE/CMakeLists.txt
badd +1 brii_CORE/main_core.h
badd +12 brii_COOKER/main_Cooker.cpp
badd +1 brii_COOKER/dataCooker.h
badd +1 learningOpenGL/STB_IMAGE_IMPLEMENT.cpp
badd +12 brii_COOKER/CMakeLists.txt
badd +38 Graphics/CMakeLists.txt
badd +17 Platform/Private/FileSystem_OS/standardLib/FileSystem_SCPP.cpp
badd +495 /usr/include/c++/16/bits/ios_base.h
badd +43 /usr/include/bits/fcntl-linux.h
badd +1 brii_CORE/dataManager/containerTypes_manager.cpp
badd +131 /usr/include/bits/types.h
badd +74 /usr/include/bits/typesizes.h
badd +160 /usr/include/sys/stat.h
badd +63 brii_CORE/Localization/LocalizationString_brii.h
badd +36 Graphics/Public/Graphics_Interface/IGraphics_brii.h
badd +26 brii_CORE/systemManager/logger.h
badd +22 brii_CORE/systemManager/logger.cpp
badd +1 Platform/Public/Platform_Brii/Platform_Log.h
badd +83 brii_CORE/Settings/Settings_LogEngine.h
badd +1 brii_CORE/dataManager/algorithms_brii.cpp
badd +1 Platform/Private/Platform_SDL/Public/SDL3_Input.cpp
badd +8 Graphics/Public/Graphics_Interface/IGraphics_brii.cpp
badd +1104 /usr/include/c++/16/bits/unique_ptr.h
badd +1 Graphics/Public/RHI_Settings/RHI_Factory.h
badd +18 Graphics/Private/IG_OpenGL/IGraphics_OpenGL.cpp
badd +118 learningOpenGL/learningOpenGL.cpp
badd +1 learningOpenGL/main_EngineBrii/Private/main_SDL.cpp
badd +26 Platform/Public/Platform_Brii/Log_System/Platform_logCalls.h
badd +74 Platform/Public/Platform_Brii/Log_System/Platform_Log.h
badd +1 Platform/Private/Platform_Log/generic_LogCalls.cpp
badd +235 term://~/CPP_proyects/Engine_Test//34199:/usr/bin/bash
badd +56 Platform/Private/Platform_Log/Linux/linux_LogCalls.cpp
badd +12 Platform/Public/Platform_Brii/Platform_IOS.h
badd +10 Platform/Private/Platform_Iostream/linux_IOS.cpp
badd +36 brii_CORE/String/BriiType_string.h
badd +35 brii_CORE/String/BriiType_string.cpp
badd +785 /usr/include/c++/16/string_view
badd +79 /usr/include/c++/16/bits/stringfwd.h
badd +4609 /usr/include/c++/16/bits/basic_string.h
badd +52 Platform/Private/Platform_Log/Linux/linux_Log.cpp
badd +46 brii_CORE/Settings/Settings_locString.h
badd +37 brii_CORE/Localization/LocalizationString_brii.cpp
badd +21 brii_CORE/Directories_and_Files/Private/DirAndFile_Manager.cpp
badd +29 brii_CORE/Directories_and_Files/Public/FilesAssets_brii.h
badd +1 brii_CORE/Directories_and_Files/Public/DirAssets_brii.h
badd +23 brii_CORE/Directories_and_Files/Public/DirAndFile_Manager.h
badd +15 brii_CORE/dataManager/Public/portability_variables.h
badd +4 brii_CORE/dataManager/Private/portability_variables.cpp
badd +802 term://~/CPP_proyects/Engine_Test//26896:/usr/bin/bash
badd +1 assets_engine/Localization/Directories/Log_files.csv
badd +1 assets_engine/Localization/Directories/English_Lenguage_files.csv
badd +23 brii_CORE/Directories_and_Files/Public/DirAndFiles_info.h
badd +5 brii_COOKER/DirAndFiles/Public/DirAndFiles_cook.h
badd +17 brii_COOKER/DirAndFiles/Private/DirAndFiles_cook.cpp
badd +10 Platform/Public/Platform_Brii/Platform_Types.h
badd +222 brii_CORE/files_CoreManager/files_Core.cpp
badd +4 Platform/Private/FileSystem_OS/Windows/FileSystem_Windows.cpp
badd +108 /usr/include/sys/types.h
badd +46 /usr/include/c++/16/source_location
badd +32 brii_CORE/Localization/Public/SourceLocation_brii.h
badd +9 brii_CORE/Localization/Private/SourceLocation_brii.cpp
badd +1 brii_CORE/glm_lib.h
badd +241 term://~/CPP_proyects/Engine_Test//14697:/usr/bin/bash
badd +34 brii_CORE/dataManager/uniquePtr/uniquePtrT_brii.h
badd +1 brii_CORE/dataManager/uniquePtr/uniquePtrT_brii.cpp
argglobal
%argdel
$argadd ~/CPP_proyects/Engine_Test
edit Platform/Private/FileSystem_OS/Linux/FileSystem_POSIX.cpp
argglobal
balt Platform/Public/Platform_Brii/Platform_FileSystem.h
setlocal foldmethod=manual
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=99
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
sil! 1,4fold
sil! 7,12fold
sil! 19,31fold
sil! 34,53fold
sil! 66,69fold
sil! 57,69fold
sil! 55,72fold
sil! 76,82fold
sil! 14,84fold
sil! 89,93fold
sil! 96,99fold
sil! 100,103fold
sil! 118,124fold
sil! 126,130fold
sil! 107,141fold
sil! 105,143fold
sil! 149,152fold
sil! 147,154fold
sil! 145,156fold
sil! 162,166fold
sil! 158,170fold
sil! 180,184fold
sil! 178,185fold
sil! 174,188fold
sil! 172,198fold
sil! 202,209fold
sil! 200,212fold
sil! 214,230fold
sil! 236,241fold
sil! 234,244fold
sil! 247,258fold
sil! 261,267fold
let &fdl = &fdl
let s:l = 223 - ((26 * winheight(0) + 23) / 47)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 223
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
