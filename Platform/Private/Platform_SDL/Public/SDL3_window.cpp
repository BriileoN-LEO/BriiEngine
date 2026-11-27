#pragma once

//Engine Links libraries
#include "Public/Platform_Brii/Platform_Window.h"
#include "SDL3_WindowDefinitions.h"
#include "Public/Platform_Brii/Log_System/Platform_logCalls.h"
#include "Localization/Public/LocStr_Calls.h"
//CPP libraries 
#include <cassert>

///CONTINUE HERE 25/08/2026
///Define a windows manager to save all the posible windows
///Define an enum class to save the type of windows created and save it in the SDL_Window_Context
//FOLLOW THE INSTRUCTIONS IN OBSIDIAN
 

void create_SDL_GL_Window(SDL_Window* Window, const brii::WindowSettings* Window_Settings)
{
 if (SDL_Init(SDL_INIT_VIDEO) == false)
 { 
  std::cout << "ERROR OpenGL | not init video\n";
  std::string errorGL {SDL_GetError()};
  std::cout << errorGL << "\n";
  assert(gWindow != nullptr); ///CHANGE this to other way to stop process 
 }

 else
 {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
 
  SDL_WindowFlags windowFlag{ SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY };

  Window = SDL_CreateWindow("LearningOpenGL", screenSettings::screen_w, screenSettings::screen_h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE); //Creacion de la ventana
  SDL_SetWindowAlwaysOnTop(Window, true);
  SDL_SetWindowPosition(Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

   if (Window == nullptr)
  {
   std::cout << "ERROR OpenGL | not init window\n";
   std::string errorGL {SDL_GetError()};
   std::cout << errorGL << "\n"; 
  }

   else
  {
   contextOpenGl = SDL_GL_CreateContext(Window);  //Creacion del contexto
   SDL_GL_SetSwapInterval(1); ///TEMPORAL

   if (contextOpenGl == NULL)
  {
   SDL_Log("Error al crear el contexto de OpenGL");
   SDL_Log(SDL_GetError());
   SDL_DestroyWindow(gWindow);
   SDL_Quit();
   correct_init = false;
   assert(contextOpenGl != nullptr);
  }

   else
  {
   if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) //Inializador de glad
   {
    SDL_Log("Fallo al inicializar glad");
    SDL_Log(SDL_GetError());
    bool correct_init = false;
   }
  }
 }
}

 }

namespace brii
{

struct WindowHandle
{
 SDL_Window* Window {nullptr};
};

 Window::Window(){};
 Window::~Window(){ destroy(); };
 
 bool Window::create_Window(WindowSettings* Window_Settings)
{      
  SDL_WindowFlags window_Flags {}; 
  const char* nameWindow{nullptr};
  int* def_height = &Window_Settings->height_size;
  int* def_witdh = &Window_Settings->width_size;
 
  ///GET THE API FLAG FOR SDL3

  if(Window_Settings->SetUserWindow == true)
 {
   if(!SDL_WindowDef::link_windowFlags(&Window_Settings->window_Flags, &window_Flags))
  {
   BRII_LOG_ERROR(BF_log::platform_t, "stop creation window, not link window flags");
//  std::cout << "[ERROR][WINDOW] stop creation window\n";
   return false;
  }
  
   ////CONTINUE HERE
  ///declare a new data container in locString to save the strings that the user save, to find the name of the windows faster if the user define their windows
  ///and find in the preset from engine brii for predifined string from the engine 24/11/2026 
  nameWindow = brii::getStr_allDirCategory_f( 
  }
  else if(Window_Settings->SetUserWindow == false)
 {
  SDL_WindowDef::predifined_WindowFlags(&Window_Settings->window_Flags, &window_Flags);
 
  if(!SDL_WindowDef::predifined_ResolutionWindow(def_height, def_witdh))
  {
   BRII_LOG_ERROR(BF_log::platform_t, "stop creation window, not predifined resolution window are assigned");
   return false;
  }

  nameWindow = "predifined_name_window";
 }
 
 ///consult the string of the name of the window with the windowID 
 Window_Context->Window = SDL_CreateWindow(nameWindow, *def_witdh, *def_height, window_Flags);

 ///CONTINUE HERE TO CREATE THE WINDOW TO SDL3 30/08/2026
  ///CREATE THE HASH TABLE TO SAVE ALL THE STRINGS IN RAM
  ///use the convetion type std::wstring to save special characters, defined in dataTypes_brii.h

  ////HERE CALL TO STOP THE CREATION WINDOW IF DETECTS IF CALLING THE API

  SDL_SetWindowAlwaysOnTop(Window_Context->Window , Window_Settings->setWindowsInTop);
  SDL_SetWindowPosition(Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

   if (Window == nullptr)
  {
   std::cout << "ERROR OpenGL | not init window\n";
   std::string errorGL {SDL_GetError()};
   std::cout << errorGL << "\n"; 
  } 
  
 }

 void* Window::get_WindowHandle()  
 {
   return static_cast<void*>(Window_Context->Window);
 }

  const BT_WindowID* Window::get_WindowID() 
 {
  return windows_ID;
 }

void Window::destroy()
 {  
  SDL_DestroyWindow(Window_Context->Window);
  SDL_Quit();
 }



 WindowManager::WindowManager(){};
 WindowManager::~WindowManager(){};

  void WindowManager::create_WindowContext(WindowSettings* API_settings)
{
   
  
}

 bool WindowManager::contains_window(BT_WindowID window_ID)
{
 for(auto windowFind : windows_container)
 {
  const BT_WindowID* window_get {windowFind.get_WindowID()};
  if(*window_get == window_ID)
  {
   return true;
  }
 }
 return false; 
}


  Window* WindowManager::get_WindowContext(BT_WindowID window_ID) const
 {

 }
 const Window* WindowManager::get_ConstWindowContext(BT_WindowID window_ID) const
 {

 }

}



///CHANGE THIS BRII PLATFORM | SUBSITUTE FOR BRII PLATFORM MANAGER 
/*
brii_Platform_Window::brii_Platform_Window(){};
brii_Platform_Window::~brii_Platform_Window(){};
void brii_Platform_Window::Initialize(void* API_settings)
{
 sets_GraphicsEngine::Graphics_Settings* SDL_SettingsGraphics {static_cast<sets_GraphicsEngine::Graphics_Settings*>(API_settings)};  
 
 window_SDL3.createWindow(SDL_SettingsGraphics); 
}

void* brii_Platform_Window::get_HandleWindow()
{
 return static_cast<void*>(window_SDL3.get_SDLWindow());
}
*/


