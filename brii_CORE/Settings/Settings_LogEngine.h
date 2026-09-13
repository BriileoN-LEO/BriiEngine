#pragma once 

//#include "dataManager/dataTypes_brii.h"
#include "String/stringID_brii.h"

enum class Brii_log_T : BT_FlagsU32
{
 GENERIC = 0,
 ENGINE_DATA = 1, ////THIS LOG IS TO INFORMATION RELATED TO THE ENGINE, specific for the data of the engine
 PLATFORM = 2,
 RHI = 3
};

///HERE I WILL SAVE THE LOGS SYSTEM THAT 
enum class Brii_log_File : BT_FlagsU64
{
 NOT_FILE = 0,
 INFO_ENGINE_DATA_FILE = 1,
 ERROR_ENGINE_DATA_FILE = 2,
 INFO_PLATFORM_FILE = 3,
 ERROR_PLATFORM_FILE = 4 ///platform_error.txt 

};


 namespace BF_log
{
  
 ///HERE GOES A STRING SYSTEM TO LOCALIZE THE STRINGS from category of platform
 

 static BT_StringID localization_logID{};

 using category = Brii_log_T;

 static constexpr category generic_t = Brii_log_T::GENERIC;
 static constexpr category platform_t = Brii_log_T::PLATFORM;
 static constexpr category engine_data_t = Brii_log_T::ENGINE_DATA; 
 static constexpr category rhi_t = Brii_log_T::RHI;
 
 ////////////////////////////////////////////////////////////////

 using file_w = Brii_log_File; 
 
 static constexpr file_w not_f = Brii_log_File::NOT_FILE; 
 static constexpr file_w info_platform_f = Brii_log_File::INFO_PLATFORM_FILE;
 static constexpr file_w error_platform_f = Brii_log_File::ERROR_PLATFORM_FILE; 


}


