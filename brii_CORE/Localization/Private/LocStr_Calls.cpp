
#include "Localization/Public/LocStr_Calls.h"
#include "Localization/LocalizationString_brii.h"

static BC_locStrManager* internal_app_locStrManager{ nullptr}; ///See if is better to put this out side

namespace app_BriiEngine
{

 void link_locStrManager(void* locStrM)
{
 internal_app_locStrManager = reinterpret_cast<BC_locStrManager*>(locStrM);
}


}


namespace brii
{
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
