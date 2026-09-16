
//#include "dataManager/Public/portability_variables.h"
#include "Directories_and_Files/Public/DirAndFile_Manager.h"
#include "Directories_and_Files/Public/DirAndFiles_info.h"
#include "Localization/LocalizationString_brii.h"

static BC_locStr* internal_locStrDirectories{}; 

namespace Brii_DirAndFiles
{
  
 void link_LocStrDirectories(void* locStrDirectories)
 {
   internal_locStrDirectories = static_cast<BC_locStr*>(internal_locStrDirectories);
 }

 BT_String* getDirectories_Log(BT_port_voidPtr<BF_log::file_w>& LogCategory) ///TO GET THE DIRECTORIES FROM THE LOC STRING DIRECTORIES THAT ARE SAVED
 {
  //BF_log::file_w 
  
  ///CONTINUE HERE 
  ///see is viable to put BT_port_voidPtr
  ///think if delete DirAssets_brii.h and FilesAssets_brii.h and remplace with csv files to save the files associate with the directories
  ///Write the piline of how the loc system it will called by the log
  ///thing more about how to organize the stack of the logs to seend to FilesSystem in order of files.
 }

 void save_DirectoriesInLocStr()
 {
    
 
 }
}
