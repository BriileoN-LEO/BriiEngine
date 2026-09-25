
#pragma once 

#include "dataManager/dataTypes_brii.h"

#include <iostream>
#include <source_location>

class brii_SourceLocation
{
 private:

 const char* file{};
 const char* function{};
 uint32_t line {};

 public:

 ///THIS constexpr in the constructor makes the class to be const if the variable class is a reference
 constexpr brii_SourceLocation(std::source_location loc = std::source_location::current()) :
  file(loc.file_name()),
  function(loc.function_name()), 
  line(loc.line()) {}

 constexpr brii_SourceLocation(const brii_SourceLocation& src_loc)
 {
   file = src_loc.file;
   function = src_loc.function;
   line = src_loc.line;
 }
 
 BT_String get_Str_Info() const;

};

using BT_SourceLoc = brii_SourceLocation;




