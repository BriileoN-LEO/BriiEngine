#pragma once

#include "String/stringID_brii.h"
#include "Settings/Settings_locString.h"

class Brii_localizationString
{
 private:
 BT_HashTable<BT_StringID, BT_String, hash_BT_StringID> string_container{};
 size_t limits_hashTable{}; ///DEFINE the max values that the hash table could save 

 public: 
 Brii_localizationString();
 ~Brii_localizationString();
 
 BT_StringID save_stringAndGetID(BT_String locStr);
  
};

using BC_locStr = Brii_localizationString;

///MAKE A ENUM CLASS TO JUMP
///This enum class contains all the types of containers that i will create, then 
class Brii_locString_Manager
{
 private: 
 std::array<Brii_localizationString, BF_locString::loc_container_size> localization_strings {};

 public:

};
