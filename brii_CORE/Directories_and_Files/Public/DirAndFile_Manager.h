#pragma once 

#include <iostream>
#include "Settings/Settings_LogEngine.h"

namespace Brii_DirAndFiles
{

 void link_LocStrDirectories(void* locStrDirectories);

 
  

 BT_String* getDirectories_Log(BT_port_voidPtr<BF_log::file_w>& LogCategory); ///TO GET THE DIRECTORIES FROM THE LOC STRING DIRECTORIES THAT ARE SAVED
 
 void save_DirectoriesInLocStr();  ////THIS FUNCTIONS STARTS TO EMPLACE OF AL DIRECTOIRES TO THE LOC STR DIRECTORIES

////CONTINUE HERE 14/09/2026
///if is posible the variables from filesAssets_brii.h could be pointers, delete this pointers to save space in ram and not duplicate this 
///string directors
}


