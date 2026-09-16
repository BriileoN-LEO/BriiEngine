#pragma once

#include "dataManager/dataTypes_brii.h"

///TYPES OF LOCALIZATION STRING
//the localization string will save diferents hash tables of string so each type is each category of hash table

enum class Brii_TypelocString : BT_LocStr_Flags
{
 LOG_STRING = 0, ///
 DIRECTORIES_LOG_STRING = 1 ///KEYS ID are inside = brii_CORE/Settings/Settings_LogEngine.h | with this BF_log::file_w type
};


namespace BF_locString
{

static constexpr size_t loc_container_size = 64; 

using BT_locString = Brii_TypelocString;

constexpr BT_locString log_str_t = BT_locString::LOG_STRING;
constexpr BT_locString directories_log_str_t = BT_locString::DIRECTORIES_LOG_STRING;

///This hashTable_p are the posicion of each category of string in the localization string manager
constexpr BT_LocStr_Flags log_hashTable_p = static_cast<BT_LocStr_Flags>(log_str_t);
constexpr BT_LocStr_Flags directories_hashTable_p = static_cast<BT_LocStr_Flags>(directories_log_str_t); 
}
