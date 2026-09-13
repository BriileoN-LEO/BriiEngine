
#include "Public/Platform_Brii/Log_System/Platform_Log.h"


 void Brii_logManager::insert_logCallStack(BF_log::category log_category, BT_String& message, BT_BoolStruct save_in_file, BF_log::file_w file_to_save)
 {
   Brii_log new_log{};
 
   new_log.log_category = log_category;
   new_log.messageID = Brii_StringFNV::hash_1a(message); 
   new_log.save_in_file = save_in_file;
   new_log.file_to_save = file_to_save; 
    
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

 void Brii_logManager::clean_callStack()
 { 
  logs_callStack.clear();
 }
 void Brii_logManager::clean_register()
 {
  logs_register.clear();
 }

