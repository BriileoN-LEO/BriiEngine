#include "Public/Platform_Brii/Platform_IOS.h"

//LIBRARY TO PRINT
#include <unistd.h>
#include <string.h>


namespace Brii_ios
{
  void MessageConsoleDebug(const char* message)
 {
  write(1, message, strlen(message)); 	
 }
}
