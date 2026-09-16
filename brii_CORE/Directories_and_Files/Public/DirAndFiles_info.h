#pragma once

#include <iostream> 
#include "dataManager/dataTypes_brii.h"

namespace Brii_DirectoriesEngine
{
 inline BT_String src_LocalizationStr_dir = static_cast<BT_String>(SOURCE_STRINGS_ENGINE_BRII);
 inline BT_String src_LocalizationStr_USER_dir = static_cast<BT_String>(SOURCE_STRINGS_USER_ENGINE_BRII);
 inline BT_String src_Logs_dir = static_cast<BT_String>(SOURCE_LOGS_ENGINE_BRII);
}

namespace Brii_filesEngine
{
 
 inline BT_String src_English_lenguage_files = Brii_DirectoriesEngine::src_LocalizationStr_dir + "Directories/English_Lenguage_files.csv";
 
 inline BT_String src_Log_files = Brii_DirectoriesEngine::src_LocalizationStr_dir + "Directories/Log_files.csv";


}



