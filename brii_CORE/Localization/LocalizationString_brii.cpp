
#include "LocalizationString_brii.h"
#include "Public/Platform_Brii/Log_System/Platform_logCalls.h"

 ////////////////////////LOCALIZATION STRING, PRINCIPAL HASH TABLE//////////////////////


 //Brii_localizationString::Brii_localizationString(){};
 Brii_localizationString::Brii_localizationString(BF_locString::category locStr_category, size_t limits_hashTable) : 
 locStr_category(locStr_category),
 limits_hashTable(limits_hashTable)
 {};
 Brii_localizationString::~Brii_localizationString() = default;

/*
 BT_StringID Brii_localizationString::save_stringAndGetID(BT_String locStr)
{
 BT_StringID str_ID {};
 str_ID.createID_by_str(locStr);
  
 string_container.emplace(str_ID, locStr);

 return str_ID; 
}*/

 bool Brii_localizationString::save_str(BT_String* str, BT_StringID* strID)
 {
  auto find_str {string_container.find(*strID)};

   if(find_str != string_container.end())
  {
   string_container.emplace(*strID, *str);
   return true; 
  }

  return false;
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
 
 bool Brii_localizationString::delete_str(BT_StringID* str_ID)
 {
  auto find_str {string_container.find(*str_ID) }; 

  if(find_str != string_container.end())
  {
   string_container.erase(*str_ID); 
   return true;
  } 

  return false;
 }  
 
 bool Brii_localizationString::delete_str(BT_StringID str_ID) 
 {
  return delete_str(&str_ID);
 } 


//////////////////////////////////////////////////////////////////////////////////////////

///////////////////////LOCALIZATION STRING MANAGER///////////////////////////////////////

BC_locStr* Brii_locString_Manager::operator[](const size_t* idx)
{
 BC_locStr* str_hashTable { nullptr };

 if(*idx < BF_locString::loc_container_size)
 {
  str_hashTable = localization_strings[*idx].get(); 
 }

 return str_hashTable;
}

bool Brii_locString_Manager::save_str_byCategory(BT_String* str, BT_StringID* strID, BF_locString::category* locStr_category)
{
 BC_locStr* str_hashTable {localization_strings[static_cast<BF_locString::BT_category>(*locStr_category)].get()};
 return str_hashTable->save_str(str, strID);
}


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
 return localization_strings[static_cast<BT_LocStr_Flags>(locStr_category)]->get_str_byID(stringID);
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

