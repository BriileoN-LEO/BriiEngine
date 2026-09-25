#pragma once

#include "String/stringID_brii.h"
#include "Settings/Settings_locString.h"

class Brii_localizationString
{
 private:
 BT_HashTable<BT_StringID, BT_String, hash_BT_StringID> string_container{}; 
 size_t limits_hashTable{}; ///DEFINE the max values that the hash table could save 
 BF_locString::category locStr_category{}; 

 public: 
 Brii_localizationString() = default;
 Brii_localizationString(BF_locString::category locStr_category, size_t limits_hashTable);
 ~Brii_localizationString();

 BT_StringID save_stringAndGetID(BT_String locStr);

 ///Find in the hash table if the string exists with the stringID
 BT_String* get_str_byID(BT_StringID* stringID);
 BT_String* get_str_byID(BT_StringID stringID);
 
};

using BC_locStr = Brii_localizationString;

///MAKE A ENUM CLASS TO JUMP
///This enum class contains all the types of containers that i will create, then 
class Brii_locString_Manager
{
 private: 
 std::array<BT_UniquePtr<BC_locStr>, BF_locString::loc_container_size> localization_strings{};

 public:

 constexpr Brii_locString_Manager()
 {
  localization_strings[BF_locString::log_hashTable_p] = BTL::make_unique<BC_locStr>(BF_locString::log_str_t, BF_locString::log_hashT_size);
  localization_strings[BF_locString::directories_user_hashTable_p] = BTL::make_unique<BC_locStr>(BF_locString::directories_user_str_t, BF_locString::directories_user_hashT_size);
  localization_strings[BF_locString::directories_log_hashTable_p] = BTL::make_unique<BC_locStr>(BF_locString::directories_log_str_t, BF_locString::directories_log_hashT_size);
  localization_strings[BF_locString::directories_assetsModel_hashTable_p] = BTL::make_unique<BC_locStr>(BF_locString::directories_assets_model_str_t, BF_locString::directories_assetsModel_hashT_size);

//  BT_UniquePtr<int> v = BTL::make_unique<int>(1);
 }
 
  BC_locStr* get_locStr_byCategory(BF_locString::category locStr_category); 
  
  BT_String* get_str_byCategory(BT_StringID stringID, BF_locString::category locStr_category);
  BT_String* get_str_byCategory(BT_StringID* stringID, BF_locString::category locStr_category);
   
  BT_String* get_str_byPos(BT_StringID stringID, size_t locStr_category);
  BT_String* get_str_byPos(BT_StringID* stringID, size_t locStr_category);



 ////CONTINUE BUILDING the loc to find in all locStr the strings by ID 

  
 ////CONTINUE HERE TO ABSTRACT MORE THE UNIQUE POINTER, to not put std::make_unique
  ///then implement in the file sistem the functions to find in all categories of directory the ID to get the directory string
  ///implement in the function is_writtenBytesMatch
  ///remember to link the loc_strManager from app_BriiEngine 

};

using BC_locStrManager = Brii_locString_Manager;

namespace app_BriiEngine
{
 void link_locStrManager(BC_locStrManager* locStrM);

 ///this function finds in all the directories category the string of directories
 BT_String* getStr_allDirCategory_f(BT_StringID* dir_str_ID);


 ////CONTINUE HERE
///Add some logs in the functions created.

}
