
#include "Localization/Public/SourceLocation_brii.h"


 BT_String brii_SourceLocation::get_Str_Info() const 
{
 return "File = " + BT_String(file) + " | Function = " + BT_String(function) + " | line = " + BT_String(line);
}

