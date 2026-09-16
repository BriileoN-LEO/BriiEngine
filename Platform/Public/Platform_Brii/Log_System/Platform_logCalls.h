#pragma once 

#include "Settings/Settings_LogEngine.h"

#include <source_location>

///Create the .cpp from this .h and insert the pointer of the Brii_logManager from the Application::EngineBrii 
///NOTE 09/09/2026: see if make a dedicate file .cpp to to create each function BRII_LOG to separate from OS or other question
///Use using BC_LogManager = Brii_logManager; to save the pointer here. 

namespace Brii_logCallsM
{
void link_LogManager(void* logManager);
inline constexpr BT_String string_LocationDescriptor(std::source_location& location);
inline constexpr BT_String str_categoryLog(BF_log::category& logCategory);
inline constexpr BF_log::file_w getFile_log(BF_log::category& logCategory, BF_log::log_type logType);

///this log descriptor save and show the log for each function, 
inline constexpr void logDescriptor(BF_log::category& logCategory, BF_log::log_type logType, BT_String message, bool writeLog, bool logOrigin = false,  std::source_location location = std::source_location::current());
}
//BRII_LOG is a normal type of logs, NOT WRITE IN ANY FILE
void BRII_LOG(BT_String message, bool logOrigin = false, std::source_location location = std::source_location::current());

//BRII_LOG_INFO could write in a file of logs 
void BRII_LOG_INFO(BF_log::category logCategory, BT_String message, bool writeLog = false, bool logOrigin = false,  std::source_location location = std::source_location::current()); 

void BRII_LOG_ERROR(BF_log::category logCategory, BT_String message, bool writeLog = false, bool logOrigin = false, std::source_location location = std::source_location::current());


//CONTINUE HERE, SEE HOW TO CONNECT THIS TYPES OF FUNCTIONS WITH THE CALL OF THE *appstate or the application of the mainEngine
///CREATE A LOG FUNCIONS THAT LINK THE LOG MANAGER OF THE ENGINE APPLICATION TO CALL THEM
