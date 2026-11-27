
#include "String/stringID_brii.h"
#include "Settings/Settings_locString.h"

namespace app_BriiEngine
{
 void link_locStrManager(void* locStrM); ///be carefull with the convertion type 

}

namespace private_LocStrCalls //this is for private function calls, only used by this file
{
  void save_str_in_locStr(BT_String* str, BT_StringID* strID, BF_locString::category* categoryStr); ///Save the str in LocStr from the engie
  const wchar_t* get_str_in_locStr(BT_StringID* strID, size_t category_idx);
}

namespace brii
{
 ///this function finds in all the directories category the string of directories
 //BT_String* getStr_allDirCategory_f(BT_StringID* dir_str_ID);
 //const BT_String* get_logStr(BT_StringID* logStrID);
 //const BT_String* get_Str(BT_StringID* strID);

 inline constexpr BT_StringID save_str_hash(BT_String str, BF_locString::category categoryStr)
 {
  BT_StringID strID { Brii_StringFNV::hash_1a_domain(str, static_cast<BT_LocStr_Flags>(categoryStr)) };
  private_LocStrCalls::save_str_in_locStr(&str, &strID, &categoryStr);
  return strID;
 };

 inline const wchar_t* get_str(BT_StringID* strID)
 {
  size_t category_idx { Brii_StringFNV::get_idx_domain(strID) };   
  const wchar_t* str_ { private_LocStrCalls::get_str_in_locStr(strID, category_idx) };
  return str_; //if returns nullptr = not exist 
 }

 bool delete_str(BT_StringID* strID);

}


