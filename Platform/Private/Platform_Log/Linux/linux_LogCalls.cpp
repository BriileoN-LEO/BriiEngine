
#include "Public/Platform_Brii/Log_System/Platform_logCalls.h"
#include "Public/Platform_Brii/Log_System/Platform_Log.h"
#include "Public/Platform_Brii/Platform_IOS.h"


static BC_LogManager* internal_LogManager { nullptr };

namespace Brii_logCallsM
{
 void link_LogManager(void* logManager)
 {
  BC_LogManager* log_manager {static_cast<BC_LogManager*>(logManager)};
  internal_LogManager = log_manager;
 }

 inline constexpr BT_String string_LocationDescriptor(std::source_location& location)
 {
  BT_String loc { "fileName = "};
  loc += location.file_name();

  return BT_String(location.file_name() + location.line());
 }

 inline constexpr BT_String str_categoryLog(BF_log::category& logCategory)
 {
   switch (logCategory)
   {
    case BF_log::general_t :
    {
     return BT_String("[GENERAL]");
    }
    case BF_log::engine_data_t : 
     {
      return BT_String("[ENGINE_DATA]");
     }
    case BF_log::platform_t : 
     { 
      return BT_String("[PLATFORM]");
     }
    case BF_log::rhi_t : 
     {
      return BT_String("[RHI]");
     }
   }
  
 }

 inline constexpr void logDescriptor(BF_log::category& logCategory, BF_log::log_type logType, BT_String message, bool writeLog, bool logOrigin,  std::source_location location)
{
  BT_String log {"[LOG_INFO]" + Brii_logCallsM::str_categoryLog(logCategory) + message + " "};
 
 if(logOrigin == true)
 { 
  log += Brii_logCallsM::string_LocationDescriptor(location);
 }

 log += " \n";

 Brii_ios::MessageToConsoleDebug(message.Tchar_ptr());
  
 if(writeLog == true)
 {
 BF_log::file_w file_to_save {BF_log::getFile_w(logCategory, logType)};
 internal_LogManager->insert_logCallStack(logCategory, message, writeLog, file_to_save);
 }
 
 else if(writeLog == false)
 {
  internal_LogManager->insert_logCallStack(logCategory, message, writeLog);
 }

}
 
}


void BRII_LOG(BT_String message, bool logOrigin, std::source_location location)
{ 
 BT_String log{"[LOG]" + message + " "};

 if(logOrigin)
 {
  log += Brii_logCallsM::string_LocationDescriptor(location);
 }

 Brii_ios::MessageToConsoleDebug(message.Tchar_ptr());
	///08/09/2026
 ///Continue here, change the name of the namespace of the functions to print, functions to the string dedicated to BT_String, if is modified in the future
 ///with other type of string i will create.

};

void BRII_LOG_INFO(BF_log::category logCategory, BT_String message, bool writeLog, bool logOrigin, std::source_location location)
{
  Brii_logCallsM::logDescriptor(logCategory, BF_log::info, message, writeLog, logOrigin, location);
 ///THINGS TO DO 13/09/2026
 ///continue with the implementation of function of the log Manager.
 ///complete the class of localization string.
 ///see how to manage the log_callstack for write in files with filemanager


};

void BRII_LOG_ERROR(BF_log::category logCategory, BT_String message, bool writeLog, bool logOrigin, std::source_location location)
{
 Brii_logCallsM::logDescriptor(logCategory, BF_log::error, message, writeLog, logOrigin, location);
};

