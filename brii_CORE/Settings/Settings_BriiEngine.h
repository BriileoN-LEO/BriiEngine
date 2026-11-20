#pragma once

#include "Settings_WindowEngine.h"
#include <iostream>

///SELECTION OF THE GRAPHICS API

 enum class Brii_Renderer_API : BT_FlagsU8
 {
  OpenGL = 0, ///AVAILABLE 
  Vulkan, //NOT AVAILABLE
  DirectX12, //NOT AVAILABLE 
  Metal //NOT AVAILABLE
 };



namespace BF_EngineSet
{
 using render_API = Brii_Renderer_API; 
 
 inline constexpr render_API OpenGL_API = render_API::OpenGL;
 inline constexpr render_API Vulkan_API = render_API::Vulkan;

}



////CONTINUE HERE 28/08/2026
////SEE WHAT I WILL DO WITH THIS, is posible to make
///Make a vector of window settings an the window will get a pointer of the Brii_WindowSettings
///Update the window by only call the window update, and in this place only modify the windows_Setting, because all is link via the pointer 
///Only have one Brii_GraphicsSettings

//SEE WHERE I COULD SAVE THE SETTINGS THE CHANGE OF API CONTEXT 

