#pragma once

#include "dataManager/dataTypes_brii.h"

///TYPES OF LOCALIZATION STRING
//the localization string will save diferents hash tables of string so each type is each category of hash table

enum class Brii_TypelocString : BT_LocStr_Flags
{
 LOG_STRING = 0, ///
 
 ///STRING FOR DIRECTORIES
 DIRECTORIES_USER_STRING = 1,
 DIRECTORIES_LOG_STRING = 2, ///KEYS ID are inside = brii_CORE/Settings/Settings_LogEngine.h | with this BF_log::file_w type
 DIRECTORIES_ASSETS_MODEL_STR = 3,
 
//// TOTAL_SIZE = 4 
};


namespace BF_locString
{

using category = Brii_TypelocString;

inline constexpr category log_str_t = category::LOG_STRING;
inline constexpr category directories_user_str_t = category::DIRECTORIES_USER_STRING;
inline constexpr category directories_log_str_t = category::DIRECTORIES_LOG_STRING;
inline constexpr category directories_assets_model_str_t = category::DIRECTORIES_ASSETS_MODEL_STR;

///This hashTable_p are the posicion of each category of string in the localization string manager
inline constexpr BT_LocStr_Flags log_hashTable_p = static_cast<BT_LocStr_Flags>(log_str_t);
inline constexpr BT_LocStr_Flags directories_user_hashTable_p = static_cast<BT_LocStr_Flags>(directories_assets_model_str_t);
inline constexpr BT_LocStr_Flags directories_log_hashTable_p = static_cast<BT_LocStr_Flags>(directories_log_str_t);
inline constexpr BT_LocStr_Flags directories_assetsModel_hashTable_p = static_cast<BT_LocStr_Flags>(directories_assets_model_str_t);

inline constexpr size_t log_hashT_size = 10000;
inline constexpr size_t directories_user_hashT_size = 10000;
inline constexpr size_t directories_log_hashT_size = 100;
inline constexpr size_t directories_assetsModel_hashT_size = 10000;

////Number of directories category
inline constexpr BT_LocStr_Flags n_start_directories = directories_user_hashTable_p;
inline constexpr BT_LocStr_Flags n_directories_category_size = 3; 

inline constexpr size_t loc_container_size = 4;

}
