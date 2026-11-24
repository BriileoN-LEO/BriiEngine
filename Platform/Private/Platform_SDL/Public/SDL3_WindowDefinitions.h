

//SDL Libraries
#include "Settings/Settings_BriiEngine.h"
#include "SDL3_libraries.h"


//////DELETE THIS DEFINITIONS 
namespace SDL_WindowDef 
{
 
// void create_SDL_GL_Window(SDL_Window* Window, const brii::WindowSettings* Window_Settings);

 bool link_flagAPI(BF_WindowSet::windowFlags* Brii_Flags, SDL_WindowFlags* SDL_Flags);
 bool link_windowFlags(BF_WindowSet::windowFlags* Brii_Flags, SDL_WindowFlags* SDL_Flags);

 void predifined_WindowFlags(BF_WindowSet::windowFlags* Brii_Flags, SDL_WindowFlags* SDL_Flag);
 bool predifined_ResolutionWindow(int* height, int* width);
 
}

