

#include <SDL3/SDL.h> 

#include "Application_Engine/Public/Application.h"
#include "Public/Graphics_Interface/IGraphics_brii.h"
#include "Public/Platform_Brii/Platform_Window.h" 
#include "Localization/Public/LocStr_Calls.h" //to link the locStr_manager to calls


namespace Application
{

  EngineSettings::EngineSettings() = default;
  EngineSettings::~EngineSettings() = default;

  ////THIS
  void EngineSettings::insert_WindowSettings(brii::WindowSettings* wSet){};  
  void insert_GraphicsSettings(brii::GraphicsSettings* gSet){};

  const BF_EngineSet::render_API* EngineSettings::get_RendererAPI() 
  {
   return &Graphics_Set.API;
  }

  const brii::GraphicsSettings* EngineSettings::get_GraphicsSet()
  {
   return &Graphics_Set;
  }

  const brii::WindowSettings* EngineSettings::get_WindowSettings()
  {
   return &Window_Settings;
  } 



 //------ENGINE BRII------

 BriiEngine::BriiEngine(){};
 BriiEngine::~BriiEngine(){ destroy_EngineBrii(); }; 

 void BriiEngine::insert_Settings(EngineSettings* Engine_Settings_)
{

}

 void BriiEngine::init_Window()
 {
  Brii_RHI* RHI_ptr { RHI_Manager->get_RHI_RawPtr() };
  const Brii_Renderer_API* API_ptr {Engine_Settings.get_RendererAPI()}; 
  Brii_RHI_Factory::create_API_RHI(RHI_ptr, API_ptr);
  
   if (SDL_Init(SDL_INIT_VIDEO) == false)
  { 
   std::cout << "ERROR not init video\n";
   std::string errorGL {SDL_GetError()};
   std::cout << errorGL << "\n";
   return;
  } 

   

 }

 void BriiEngine::init_EngineBrii()
 {
 
  
  ////HERE PUT THE ATTRIBUTES OPENGL 

 }

 void BriiEngine::destroy_EngineBrii()
 {
 
 }

}
