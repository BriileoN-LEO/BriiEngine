#pragma once

#include "dataManager/dataTypes_brii.h"
#include "Settings/Settings_BriiEngine.h"

/*
 class Brii_Window
i{
 
 private

 public: 
 
 brii_Platform_Window();
 ~brii_Platform_Window();
 
 void Initialize_GraphicsAPI(void* API_settings);
 //void create_Window( 

 void* get_HandleWindow();

};*/

//this class is defined in SDL3_Window.cpp or other type

namespace brii
{

 struct WindowHandle;
 
 struct WindowSettings
 {
  uint64_t windowName_ID{};

  int width_size{};
  int height_size{}; 
  
  Brii_WindowFlags window_Flags{};

  bool setWindowsInTop{true};

  uint8_t SetUserWindow{ false }; ////to identify if the user set the window settings | false = not defined by user | true = defined by user
  //if is set the windows settings, it needs to declare all the data types from this class settings
  //- Assigned the windowsName_ID from the locStr 

 };

 class Window
{
  private:
  WindowHandle* Window_Context{ nullptr };
  BT_WindowID* windows_ID{ nullptr };

  public:

  Window();
  ~Window(); 
 
 bool create_Window(WindowSettings* Window_Settings);
 void* get_WindowHandle() ;
 const BT_WindowID* get_WindowID() ;
 void destroy();
};

///THE MANAGER UTILITIES
///only see if the window exist or not
///
////CONTINUE HERE TO DECLARE 

 class WindowManager
{
  private:

  BT_Vector<Window> windows_container{};
 
  public:
  WindowManager();
  ~WindowManager();

  void create_WindowContext(WindowSettings* API_settings);
  bool contains_window(BT_WindowID window_ID); 

  Window* get_WindowContext(BT_WindowID window_ID) const;
  const Window* get_ConstWindowContext(BT_WindowID window_ID) const; 
 
};
}
///link the locString with this window platform to link the names of the platform 
///Probably create here the general window manager that the application requieres to create
//multiple windows


