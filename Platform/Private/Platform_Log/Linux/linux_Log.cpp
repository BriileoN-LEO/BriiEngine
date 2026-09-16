
#include "Public/Platform_Brii/Platform_FileSystem.h"
#include "Public/Platform_Brii/Log_System/Platform_Log.h"
#include "Localization/LocalizationString_brii.h"
#include "Directories_and_Files/DirAndFile_Manager.h"

 ///THIS INTERNAL localization string is linked specific for the logs, it will save the logs like string, it needs to define a limit
 static BC_locStr* internal_locStr_log{ nullptr }; 
 static BC_FS_Manager* internal_FS_Manager{ nullptr };///HERE SAVE THE FILES SYSTEM MANAGER to call it when the log stack requiered   

  namespace Brii_logM
 {
  void link_locStrLog(void* locStrLog)
  {
   internal_locStr_log = static_cast<BC_locStr*>(locStrLog); 
  }
  void link_FS_Manager(void* FS_Manager)
  { 
   internal_FS_Manager = static_cast<BC_FS_Manager*>(FS_Manager); 
  }
 }

 void Brii_logManager::insert_logCallStack(BF_log::category log_category, BT_String& message, BT_BoolStruct save_in_file, BF_log::file_w file_to_save)
 {
   Brii_log new_log{};
 
   new_log.log_category = log_category;
   new_log.messageID = Brii_StringFNV::hash_1a(message); 
   new_log.save_in_file = save_in_file;
   new_log.file_to_save = file_to_save; 
    
   ///CONTINUE HERE 13/09/2026
   ///-Get the directories saved in the loc string
   ///-Consult the directories via to loc string with getting the ID with the numbers of BF_log::file_w
   ///-See settings_log to know how to resolve to consult the directories via the ID and how to save this ID,
   ///with some global ID that links with BF_log::file_w to know how to grab each ID and consult the str_localization
   
   
	 ///CONTINUE HERE 10/09/2026
  //THINSG TO DO
  ///-Register the messageID in the localization of strings
  ///-Create this functions of the log manager
  ///-Implement this functions in the log calls to register the logs if it will be need to saved.
  ///-Register the new data in the documentation in Obsidian.
 }
 void Brii_logManager::register_log(Brii_log& log_toRegister)
 {

  
 }

 void Brii_logManager::upload_LogsCallStack_FS()
 { 
  internal_FS_Manager.insert_FS_stackWrite(message.Tchar_ptr(), 
 
   ///HERE UPLOAD IN ORDER
 }
 
 

 void Brii_logManager::clean_callStack()
 { 
  logs_callStack.clear();
 }
 void Brii_logManager::clean_register()
 {
  logs_register.clear();
 }

