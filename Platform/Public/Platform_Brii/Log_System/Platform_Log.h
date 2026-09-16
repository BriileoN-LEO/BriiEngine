#pragma once

#include "Settings/Settings_LogEngine.h"
#include "String/stringID_brii.h"

#include <source_location>

/*
struct Brii_logContext
{
 Brii_log_T logType{};
 BT_StringID_64 log_str{};
 BT_BoolStruct save_in_file{}; ///IF THIS LOG NEED TO BE SAVE IN FILE
 //std::string name_log_T{};
};*/

namespace Brii_logM
{
 void link_locStrLog(void* locStrLog);
 void link_FS_Manager(void* FS_Manager);
}

struct Brii_log
{
 BF_log::category log_category{};
 BT_StringID messageID{};

 BF_log::file_w file_to_save{};
 BT_BoolStruct save_in_file{}; ///IF THIS LOG NEED TO BE SAVE IN FILE
 //std::string name_log_T{};
 
 ///HERE SAVE A VECTOR OF BE_logContext 
 ///Think more about how to implement this logger in a better way
 ///Change the logs from files:
 //-Platform/Private/Platform_SDL/SDL3_window.cpp 

};

struct Brii_logRegister
{
  BT_StringID register_logStr{}; ///ID saved in the string localization

 //MPLEMENT A TIME REGISTER FOR THIS LOGS, insert the time when it was call the log from the logs  
};

class Brii_logManager
{
 //KEY ASPECTS
 ///-When the log of callstack is printed the content will go to the logs_register stack and it will be deleted from logs_callStack

 private:
 std::vector<Brii_log> logs_callStack{};
 std::vector<Brii_logRegister> logs_register{};
 
 public:

 Brii_logManager();
 ~Brii_logManager();
 
 void insert_logCallStack(BF_log::category log_category, BT_String& message, BT_BoolStruct save_in_file = false, BF_log::file_w file_to_save = BF_log::not_f);
 void register_log(Brii_log& log_toRegister);
  
 ////This function will upload the logs of the callstack in the FS
 ///in every second if there is some logs that it will need to callstack
 void upload_LogsCallStack_FS();

 void clean_callStack();
 void clean_register();
 //clean_register functions to implement
 ///-It will call the string localization to empty strings that are from the ram
 
  ///the initialization of this log will create all the logs available in the log Type 

};

using BC_LogManager = Brii_logManager; 


