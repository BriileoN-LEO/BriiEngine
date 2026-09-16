
#include "DirAndFiles/Public/DirAndFiles_cook.h"
#include "Public/Platform_Brii/Platform_Types.h"
#include "Public/Platform_Brii/Log_System/Platform_logCalls.h"
#include "brii_CORE/Directories_and_Files/Public/DirAndFiles_info.h"

void write_LogFilesCSV()
{
  constexpr BT_String& logFile_csv {Brii_filesEngine::src_Log_files};
  BT_Platform::FileSystem log_file_w {logFile_csv, BF_Ios::o_createF | BF_Ios::o_writeF | BF_Ios::o_truncF, BF_Ios::op_standard};
 
  if(!log_file_w.is_open())
  {
   BRII_LOG_ERROR(BF_log::engine_data_t, BT_String("not write the files of log in the csv"), true, true);
  }


  ///HERE WRITE IN THE CSV FILE THE SETTINGS FOR THE LOG FILES 
 

}

//This function writes the origin of the logs 
