 
#include "Public/Platform_Brii/Platform_FileSystem.h"

#include <fstream>

namespace FS_StandardCppDef
{

  void link_FS_flags_OpenMode(const BF_Ios::openMode* open_flags, BT_ComponentFlagsInt* flags, BF_Ios::openPermissions open_permissions)
 {
  *flags |= (*open_flags && BF_Ios::o_binary ) ? std::ios::binary : 0;
 
  //*flags |= (
    

 } 


}
