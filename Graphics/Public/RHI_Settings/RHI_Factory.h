#ifndef RHI_ENGINE_BRII
#define RHI_ENGINE_BRII 

#include "Settings/Settings_BriiEngine.h"
#include "Public/Graphics_Interface/IGraphics_brii.h"  

namespace brii
{
  struct GraphicsSettings 
 { 
   BF_EngineSet::render_API API{};

    //work API version | OpenGL and Vulkan
   int API_majorVersion{};
   int API_minorVersion{};


 };

 void create_API_RHI(Brii_RHI* RHI, const Brii_Renderer_API* API);


}
 
namespace brii_rhi
{ 
  brii::GraphicsSettings predifined_GraphicsSettings();
}




#endif //RHI_ENGINE_BRII
