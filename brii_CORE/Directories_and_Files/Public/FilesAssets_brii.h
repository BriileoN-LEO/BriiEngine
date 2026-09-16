#pragma once

#include "DirAssets_brii.h"

namespace Brii_filesEngine
{
  

  namespace English_Lenguage
 { 
  
  
  static BT_String src_dir_english = Brii_DirectoriesEngine::src_LocalizationStr_dir + "English_Lenguage/"; 
  
  static BT_String principal_window = src_dir_english + "Principal_Window.csv";
 } 

}

///PUT THIS LOGS INFORMATION IN SEPARTED FILE 
namespace Brii_filesLogs
{ 
 static BT_String general = Brii_DirectoriesEngine::src_Logs_dir + "general_log.txt";

 static BT_String info_engine_data = Brii_DirectoriesEngine::src_Logs_dir + "info_engine_data_log.txt";
 static BT_String info_platform =  Brii_DirectoriesEngine::src_Logs_dir + "info_platform_log.txt";
 static BT_String info_rhi =  Brii_DirectoriesEngine::src_Logs_dir + "info_rhi_log.txt";

 static BT_String error_engine_data =  Brii_DirectoriesEngine::src_Logs_dir + "error_engine_data_log.txt";
 static BT_String error_platform_file =  Brii_DirectoriesEngine::src_Logs_dir + "error_platform_log.txt";
 static BT_String error_rhi_file =  Brii_DirectoriesEngine::src_Logs_dir + "error_rhi_log.txt";
}


