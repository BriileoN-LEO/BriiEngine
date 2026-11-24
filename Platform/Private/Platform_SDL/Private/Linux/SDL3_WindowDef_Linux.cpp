#include "Private/Platform_SDL/Public/SDL3_WindowDefinitions.h"


namespace SDL_WindowDef
{

bool link_flagAPI(Brii_WindowFlags* Brii_Flags, SDL_WindowFlags* SDL_Flags)
{
   if(*Brii_Flags && BF_WindowSet::window_OpenGL_F)
   {
    *SDL_Flags |= SDL_WINDOW_OPENGL;
    return true;
   }
  
   else if(*Brii_Flags && BF_WindowSet::window_Vulkan_F)
   {
    std::cout << "[ERROR] getting SDL_flag API | Vulkan API is not available yet\n";
//    *API ^= Brii_WindowFlags::BRII_WINDOW_VULKAN;
//    *API |= Brii_WindowFlags::BRII_WINDOW_OPENGL;
   }

   else if(*Brii_Flags && BF_WindowSet::window_DirectX12_F)
   {
    std::cout << "[ERROR] getting SDL_flag API | DirectX12 is not available in Linux";
//    *API ^= Brii_WindowFlags::BRII_WINDOW_DIRECTX12;
//    *API |= Brii_WindowFlags::BRII_WINDOW_OPENGL;
   }

   else if(*Brii_Flags && BF_WindowSet::window_Metal_F)
   {
    std::cout << "[ERROR] getting SDL_flag API | Metal is not available in Linux";
//    *API ^= Brii_WindowFlags::BRII_WINDOW_METAL;
//    *API |= Brii_WindowFlags::BRII_WINDOW_OPENGL;
   }

 ///HERE TWROW FALSE TO AND ERROR MANAGER AND STOPS THE FUNCTION TO CONTINUE BUILDING THE WINDOW
///IN THE CASE THAT THE FLAG GRAPHICS API OF THE WINDOW NOT MATCH WITH THE RHI API, CALL TO REBUILD THE WINDOW
	///*This because OpenGL needs a context and if the api was OpenGL and the Window calls to vulkan, we need to
	///delete the context of OpenGL. 
  return false;
}

 bool link_windowFlags(Brii_WindowFlags* Brii_Flags, SDL_WindowFlags* SDL_Flags)
 {
 ///THIS FUNCTION LINK THE FLAGS THAT OF BRII_WINDOWFLAGS WITH THE SDL_WINDOWFLAGS
  if(*Brii_Flags && BF_WindowSet::window_hidden_F)
  {
   *SDL_Flags |= SDL_WINDOW_HIDDEN; 
  }
  
  if(*Brii_Flags && BF_WindowSet::window_high_pixel_density_F)
  {
   *SDL_Flags |= SDL_WINDOW_HIGH_PIXEL_DENSITY;
  }

  if(*Brii_Flags && BF_WindowSet::window_resizable_F)
  {
   *SDL_Flags |= SDL_WINDOW_RESIZABLE;
  }

  if(!link_flagAPI(Brii_Flags, SDL_Flags))
  {
   return false;
  }

 return true;
}


 void predifined_WindowFlags(BF_WindowSet::windowFlags* Brii_Flags, SDL_WindowFlags* SDL_Flags)
 {
   *Brii_Flags = BF_WindowSet::window_OpenGL_F | BF_WindowSet::window_hidden_F | BF_WindowSet::window_high_pixel_density_F | BF_WindowSet::window_resizable_F;
   *SDL_Flags = SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_RESIZABLE;
 }

 bool predifined_ResolutionWindow(int* height, int* width)
 {
  if(SDL_WasInit(SDL_INIT_VIDEO) == 0)
   {
    return false;
   }

  SDL_DisplayID main_displayID = SDL_GetPrimaryDisplay();
  const SDL_DisplayMode* main_displayMode = SDL_GetCurrentDisplayMode(main_displayID);

  *height = static_cast<int>(main_displayMode->h * main_displayMode->pixel_density);
  *width = static_cast<int>(main_displayMode->w * main_displayMode->pixel_density);

  return true;
 }
}




