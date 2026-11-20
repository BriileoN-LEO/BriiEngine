

//SDL Libraries
#include "Settings/Settings_BriiEngine.h"
#include "SDL3_libraries.h"

//CPP Libraries
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>


//////DELETE THIS DEFINITIONS 
namespace SDL_WindowDef 
{
 
// void create_SDL_GL_Window(SDL_Window* Window, const brii::WindowSettings* Window_Settings);

 bool link_flagAPI(BF_WindowSet::windowFlags* Brii_Flags, SDL_WindowFlags* SDL_Flags);
 bool link_windowFlags(BF_WindowSet::windowFlags* Brii_Flags, SDL_WindowFlags* SDL_Flags);

}

