#pragma once

#include "dataManager/dataTypes_brii.h"

enum class Brii_locString_Tpos : BT_FlagsU64
{
 LOG_STRING = 0,
 

};


namespace BF_locString
{

static constexpr size_t loc_container_size = 64; 

using BT_locString_pos = Brii_locString_Tpos;




}
