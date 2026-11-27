#pragma once

#include "dataManager/dataTypes_brii.h"

///TYPES OF LOCALIZATION STRING
//the localization string will save diferents hash tables of string so each type is each category of hash table

enum class Brii_TypelocString : BT_LocStr_Flags
{
 LOG_STRING = 0, ///
 
 ///STRING FOR DIRECTORIES
 DIRECTORIES_USER_STRING = 1, ///strings that the user create from the engine, like change the name and other stuff
 DIRECTORIES_LOG_STRING = 2, ///KEYS ID are inside = brii_CORE/Settings/Settings_LogEngine.h | with this BF_log::file_w type
 DIRECTORIES_ASSETS_MODEL_STR = 3, ///directories from the assets of the user and the engine

 BRII_ENGINE_PRESETS_STR = 4, //strings that need the engine for the UI or other stuff, like windows names, etc.
 BRII_ENGINE_USER_STR = 5 // this 
//// TOTAL_SIZE = 4 
};

namespace BF_locString
{
 
using category = Brii_TypelocString;
using BT_category = std::underlying_type_t<Brii_TypelocString>;

inline constexpr category log_str_t = category::LOG_STRING;
inline constexpr category directories_user_str_t = category::DIRECTORIES_USER_STRING;
inline constexpr category directories_log_str_t = category::DIRECTORIES_LOG_STRING;
inline constexpr category directories_assets_model_str_t = category::DIRECTORIES_ASSETS_MODEL_STR;
inline constexpr category briiEngine_presets_str_t = category::BRII_ENGINE_PRESETS_STR;
inline constexpr category briiEngine_user_str_t = category::BRII_ENGINE_USER_STR;

///This hashTable_p are the posicion of each category of string in the localization string manager
inline constexpr BT_LocStr_Flags log_hashTable_p = static_cast<BT_LocStr_Flags>(log_str_t);
inline constexpr BT_LocStr_Flags directories_user_hashTable_p = static_cast<BT_LocStr_Flags>(directories_user_str_t);
inline constexpr BT_LocStr_Flags directories_log_hashTable_p = static_cast<BT_LocStr_Flags>(directories_log_str_t);
inline constexpr BT_LocStr_Flags directories_assetsModel_hashTable_p = static_cast<BT_LocStr_Flags>(directories_assets_model_str_t);
inline constexpr BT_LocStr_Flags briiEngine_presets_hashTable_p = static_cast<BT_LocStr_Flags>(briiEngine_presets_str_t);
inline constexpr BT_LocStr_Flags briiEngine_user_hashTable_p = static_cast<BT_LocStr_Flags>(briiEngine_user_str_t);

inline constexpr size_t log_hashT_size = 10000;
inline constexpr size_t directories_user_hashT_size = 10000;
inline constexpr size_t directories_log_hashT_size = 100;
inline constexpr size_t directories_assetsModel_hashT_size = 10000;
inline constexpr size_t brii_engine_presets_size = 10000;
inline constexpr size_t brii_engine_user_size = 10000;

////Number of directories category | this numbers are to loop from the hash table
inline constexpr BT_LocStr_Flags n_start_StrStandard = log_hashTable_p;
inline constexpr BT_LocStr_Flags n_end_StrStandard = directories_user_hashTable_p;
inline constexpr BT_LocStr_Flags n_start_directories = directories_user_hashTable_p;
inline constexpr BT_LocStr_Flags n_directories_category_size = 3; 

inline constexpr size_t loc_container_size = 6;

}
