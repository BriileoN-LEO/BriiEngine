
#include "String/stringID_brii.h"

namespace app_BriiEngine
{
 void link_locStrManager(void* locStrM); ///be carefull with the convertion type 

}

namespace brii
{
 ///this function finds in all the directories category the string of directories
 BT_String* getStr_allDirCategory_f(BT_StringID* dir_str_ID);

 const BT_String* get_logStr(BT_StringID* logStrID);
 const BT_String* get_Str(BT_StringID* strID);

 bool delete_str_locStr(BT_StringID* strID); 
 

}
