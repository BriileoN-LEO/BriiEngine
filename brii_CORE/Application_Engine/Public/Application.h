#pragma once

#include "Public/Platform_Brii/Platform_Window.h"
#include "Public/Platform_Brii/Platform_FileSystem.h"
#include "Public/RHI_Settings/RHI_Factory.h"
#include "Public/Platform_Brii/Log_System/Platform_Log.h"
#include "systemManager/logger.h"
#include "Public/CoreSystems_Brii/Job_Schedule.h"
#include "Localization/LocalizationString_brii.h"
//#include "Settings/Settings_BriiEngine.h"
//#include "Settings/Settings_WindowEngine.h" 
#include <iostream> 

namespace Application
{
 
  class EngineSettings
 {
  private:
 
  brii::WindowSettings Window_Settings{};
  brii::GraphicsSettings Graphics_Set{};

  public:

  EngineSettings();
  ~EngineSettings();

  ////THIS
  void insert_WindowSettings(brii::WindowSettings* wSet);  
  void insert_GraphicsSettings(brii::GraphicsSettings* gSet);

  const BF_EngineSet::render_API* get_RendererAPI();
  const brii::GraphicsSettings* get_GraphicsSet();
  const brii::WindowSettings* get_WindowSettings();
 };



  class BriiEngine
 {
  private:
  
  BT_UniquePtr<brii::WindowManager> window_Manager{}; 
  BT_UniquePtr<Brii_RHI_Manager> RHI_Manager{};
  BT_UniquePtr<Brii_logManager> Log_Manager{}; ///THIS LOG CONTAINS ALL THE LOG TYPES FOR THE ENGIN
  BT_UniquePtr<Brii_FileSystem_Manager> FS_Manager{}; 
  BT_UniquePtr<brii::JobSystem> JobSystem_Manager{};
  BT_UniquePtr<brii::locString_Manager> locStr_Manager{};

  //Main settings for the principal Window of the Engine 
  EngineSettings Engine_Settings{};

  public:

  BriiEngine();
  ~BriiEngine();

  void insert_Settings(EngineSettings Engine_Settings);
 
  void init_Window();
  void init_EngineBrii();
  void destroy_EngineBrii();

 };

/*
////QUIT THIS IN THE FUTURE 
///EXAMPLE IF I WILL HAVE MULTIPLE WINDOWS, HOW I WILL BE CREATE
 class Brii_UI_Engine
{
 private: 

  ///THIS LINK IS FOR THE WINDOW GET BY THE ENGINE, WITH THE WindowManager 
 Brii_Window* link_Window{};
 Brii_WindowSettings Window_Settings{};
  
 public:


};
*/

}
