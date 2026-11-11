
#include "LocalizationString_brii.h"
#include "Public/Platform_Brii/Log_System/Platform_logCalls.h"

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

 const BT_String* get_logStr(BT_StringID* logStrID)
 { 
  return internal_app_locStrManager->get_str_byCategory(logStrID, BF_locString::log_str_t);
 }
 
 const BT_String* get_Str(BT_StringID* strID)
 {
   for(BF_locString::BT_category i = BF_locString::n_start_StrStandard; i < BF_locString::n_end_StrStandard; i++)
  {
   const BT_String* str { internal_app_locStrManager->get_str_byPos(strID, i) };
   
   if(str != nullptr)
   {
    return str;
   }
  }  
   
  return nullptr;
 }

 bool delete_str_locStr(BT_StringID* strID)
 {
   for(size_t i = 0; i < BF_locString::loc_container_size; i++)
  {
    BC_locStr* locStr_c {internal_app_locStrManager->get_locStr_byCategory(static_cast<BF_locString::category>(i)) }; 
    bool del_str {locStr_c->delete_str(strID)};
   
    if(del_str)
   { 
    return true;
   }

  }
 
  return false;
 }

}

