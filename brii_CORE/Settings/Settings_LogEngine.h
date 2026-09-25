#pragma once 

//#include "dataManager/dataTypes_brii.h"
#include "String/stringID_brii.h"

using BT_logT = BT_FlagsU32;
using BT_logCategory = BT_FlagsU64; ////LOGS CATEGORY ALWAYS HAVE THE BIGGEST TYPE OF VALUE

enum class Brii_log_T : BT_logT
{
 LOG_INFO = 1,
 LOG_ERROR = 3
};

enum class Brii_log_category :BT_logCategory
{
 GENERAL = 0, //[0000]
 ENGINE_DATA = 1,//[0001]         ////THIS LOG IS TO INFORMATION RELATED TO THE ENGINE, specific for the data of the engine
 PLATFORM = 2,//[0010]
 RHI = 3, //[0011]
 FILE_SYSTEM = 4 //[0100]
};

namespace Brii_logDef_V ////Log definitions values of each enum class 
{
static constexpr BT_logCategory info_t = static_cast<BT_logCategory>(Brii_log_T::LOG_INFO);
static constexpr BT_logCategory error_t = static_cast<BT_logCategory>(Brii_log_T::LOG_ERROR); 

inline constexpr BT_logCategory general_c = static_cast<BT_logCategory>(Brii_log_category::GENERAL);
inline constexpr BT_logCategory engine_data_c = static_cast<BT_logCategory>(Brii_log_category::ENGINE_DATA);
inline constexpr BT_logCategory platform_c = static_cast<BT_logCategory>(Brii_log_category::PLATFORM);
inline constexpr BT_logCategory rhi_c = static_cast<BT_logCategory>(Brii_log_category::RHI);
inline constexpr BT_logCategory file_system_c = static_cast<BT_logCategory>(Brii_log_category::FILE_SYSTEM);
} 

///HERE I WILL SAVE THE LOGS SYSTEM THAT 
 enum class Brii_log_File : BT_logCategory
{
 GENERAL_FILE = Brii_logDef_V::general_c, //[0000]

 INFO_ENGINE_DATA_FILE = Brii_logDef_V::engine_data_c << Brii_logDef_V::info_t, //[0010]
 INFO_PLATFORM_FILE = Brii_logDef_V::platform_c << Brii_logDef_V::info_t, //[0100]
 INFO_RHI_FILE = Brii_logDef_V::rhi_c << Brii_logDef_V::info_t, //[0110]
 INFO_FILE_SYSTEM_F = Brii_logDef_V::file_system_c << Brii_logDef_V::info_t, //[1000]

 ERROR_ENGINE_DATA_FILE = Brii_logDef_V::engine_data_c << Brii_logDef_V::error_t, //[1000]
 ERROR_PLATFORM_FILE = Brii_logDef_V::platform_c << Brii_logDef_V::error_t, //[0001 0000]    ///platform_error.txt 
 ERROR_RHI_FILE = Brii_logDef_V::rhi_c << Brii_logDef_V::error_t, //[0001 1000]
 ERROR_FILE_SYSTEM_F = Brii_logDef_V::file_system_c << Brii_logDef_V::error_t, //[0010 0000]

 NOT_FILE = 1 << 12
};


namespace BF_log
{
 
 using log_type = Brii_log_T;

 inline constexpr log_type info = Brii_log_T::LOG_INFO;
 inline constexpr log_type error = Brii_log_T::LOG_ERROR;

 using category = Brii_log_category;

 inline constexpr category general_t = Brii_log_category::GENERAL;
 inline constexpr category platform_t = Brii_log_category::PLATFORM;
 inline constexpr category engine_data_t = Brii_log_category::ENGINE_DATA; 
 inline constexpr category rhi_t = Brii_log_category::RHI;
 inline constexpr category file_system_t = Brii_log_category::FILE_SYSTEM;
 
 ////////////////////////////////////////////////////////////////

 using file_w = Brii_log_File; 

 ///USED TO GET THE DIRECTORIES FROM THE DIRECTORIES_LOG_STRING

 inline constexpr file_w not_f = Brii_log_File::NOT_FILE;

 inline constexpr file_w general_f = Brii_log_File::GENERAL_FILE; ///IF WRITE general_f, the type of log is ignore because general_f is [0000] zero
 
 inline constexpr file_w info_engine_data_f = Brii_log_File::INFO_ENGINE_DATA_FILE;
 inline constexpr file_w info_platform_f = Brii_log_File::INFO_PLATFORM_FILE;

 inline constexpr file_w error_engine_data_f = Brii_log_File::ERROR_ENGINE_DATA_FILE;
 inline constexpr file_w error_platform_f = Brii_log_File::ERROR_PLATFORM_FILE; 

  inline constexpr file_w getFile_w(category& logCategory, log_type logType)
 { 
  return static_cast<file_w>(static_cast<BT_logCategory>(logCategory) << static_cast<BT_logT>(logType));
 }
 

 

}



