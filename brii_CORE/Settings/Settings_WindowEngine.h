#pragma once

#include "dataManager/dataTypes_brii.h"

enum class Brii_WindowType : BT_FlagsU16
 {
  PRINCIPAL_WINDOW = 0,
  VIEWPORT = 1,
  RENDER = 2,
  TREEWORK_VIEW = 3
 };


enum class Brii_WindowFlags : BT_Window_Flags
{
 //API
 BRII_WINDOW_OPENGL = 1,
 BRII_WINDOW_VULKAN = 1 << 1, 
 BRII_WINDOW_DIRECTX12 = 1 << 2,
 BRII_WINDOW_METAL = 1 << 3, 

 //WINDOW CONFIG
 BRII_WINDOW_RESIZABLE = 1 << 4,
 BRII_WINDOW_HIDDEN = 1 << 5, 
 BRII_WINDOW_HIGH_PIXEL_DENSITY = 1 << 6, 

};

template<> inline constexpr bool is_bitmask_flag<Brii_WindowFlags> = true;

//SDL_WindowFlags windowFlag{ SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY };

namespace BF_WindowSet
{
 using windowType = Brii_WindowType; 

 inline constexpr windowType principal_WindowT = windowType::PRINCIPAL_WINDOW;
 inline constexpr windowType viewport_WindowT = windowType::VIEWPORT;
 inline constexpr windowType render_WindowT = windowType::RENDER;
 inline constexpr windowType treeworkView_WindowT = windowType::TREEWORK_VIEW;

 using windowFlags = Brii_WindowFlags;

 inline constexpr windowFlags window_OpenGL_F = windowFlags::BRII_WINDOW_OPENGL;
 inline constexpr windowFlags window_Vulkan_F = windowFlags::BRII_WINDOW_VULKAN;
 inline constexpr windowFlags window_DirectX12_F = windowFlags::BRII_WINDOW_DIRECTX12;
 inline constexpr windowFlags window_Metal_F = windowFlags::BRII_WINDOW_METAL;
 
 inline constexpr windowFlags window_resizable_F = windowFlags::BRII_WINDOW_RESIZABLE;
 inline constexpr windowFlags window_hidden_F = windowFlags::BRII_WINDOW_HIDDEN;
 inline constexpr windowFlags window_high_pixel_density_F = windowFlags::BRII_WINDOW_HIGH_PIXEL_DENSITY;

}

