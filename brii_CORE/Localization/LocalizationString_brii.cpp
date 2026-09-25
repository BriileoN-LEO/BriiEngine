
#include "LocalizationString_brii.h"
 ////////////////////////LOCALIZATION STRING, PRINCIPAL HASH TABLE//////////////////////


 //Brii_localizationString::Brii_localizationString(){};
 Brii_localizationString::Brii_localizationString(BF_locString::category locStr_category, size_t limits_hashTable) : 
 locStr_category(locStr_category),
 limits_hashTable(limits_hashTable)
 {};
 Brii_localizationString::~Brii_localizationString() = default;
 
 BT_StringID Brii_localizationString::save_stringAndGetID(BT_String locStr)
{
 BT_StringID str_ID {};
 str_ID.createID_by_str(locStr);
  
 string_container.emplace(str_ID, locStr);

 return str_ID; 
}
   

 BT_String* Brii_localizationString::get_str_byID(BT_StringID* stringID)
 {
  auto find_strID {string_container.find(*stringID)};

   if(find_strID != string_container.end())
  { 
   return &find_strID->second;
  }
  return nullptr; 
 } 

 BT_String* Brii_localizationString::get_str_byID(BT_StringID stringID)
 {
  return get_str_byID(&stringID);
 }

//////////////////////////////////////////////////////////////////////////////////////////

///////////////////////LOCALIZATION STRING MANAGER///////////////////////////////////////

BC_locStr* Brii_locString_Manager::get_locStr_byCategory(BF_locString::category locStr_category)
{
 return localization_strings[static_cast<BT_LocStr_Flags>(locStr_category)].get(); 
}
  
BT_String* Brii_locString_Manager::get_str_byCategory(BT_StringID stringID, BF_locString::category locStr_category)
{
 return localization_strings[static_cast<BT_LocStr_Flags>(locStr_category)]->get_str_byID(&stringID);
}

BT_String* Brii_locString_Manager::get_str_byCategory(BT_StringID* stringID, BF_locString::category locStr_category)
{
 return localization_strings[static_cast<BT_LocStr_Flags>(locStr_category)]->get_str_byID(*stringID);
}

BT_String* Brii_locString_Manager::get_str_byPos(BT_StringID stringID, size_t locStr_pos)
{
 if(locStr_pos < BF_locString::loc_container_size)
 {
  return localization_strings[locStr_pos]->get_str_byID(&stringID);
 }

 return nullptr;
}

BT_String* Brii_locString_Manager::get_str_byPos(BT_StringID* stringID, size_t locStr_pos)
{
  if(locStr_pos < BF_locString::loc_container_size)
 {
  return localization_strings[locStr_pos]->get_str_byID(*stringID);
 }

 return nullptr;
}


//////////////////////////////////////////////////////////////////////////////////////////



namespace app_BriiEngine
{
 static BC_locStrManager* internal_app_locStrManager{ nullptr};

 void link_locStrManager(BC_locStrManager* locStrM)
{
 internal_app_locStrManager = locStrM;
}

 ///this function finds in all the directories category the string of directories
 BT_String* getStr_allDirCategory_f(BT_StringID* dir_str_ID)
 {
   for(BT_LocStr_Flags i = BF_locString::n_start_directories; i < BF_locString::n_directories_category_size; i++)
  {
   BT_String* str {internal_app_locStrManager->get_str_byPos(*dir_str_ID, i) };

   if(str != nullptr)
   {
    return str;
   }

  }
  return nullptr;
 } 
 

}

