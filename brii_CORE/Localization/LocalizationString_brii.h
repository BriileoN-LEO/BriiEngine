#pragma once

#include "String/stringID_brii.h"
#include "Settings/Settings_locString.h"

class Brii_localizationString
{
 private:
 BT_HashTable<BT_StringID, BT_String, hash_BT_StringID> string_container{};
 
 public: 
 Brii_localizationString();
 ~Brii_localizationString();
  
};


///MAKE A ENUM CLASS TO JUMP 
class Brii_locString_Manager
{
 private: 
 std::array<Brii_localizationString, BF_locString::loc_container_size> localization_strings {};

};
