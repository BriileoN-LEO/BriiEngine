
#include "LocalizationString_brii.h"



 Brii_localizationString::Brii_localizationString(){};
 Brii_localizationString::~Brii_localizationString() = default;
 
 BT_StringID Brii_localizationString::save_stringAndGetID(BT_String locStr)
{
 BT_StringID str_ID {locStr};
  
 string_container.emplace(str_ID, locStr);

 return str_ID; 
}

