
#include "stringID_brii.h"

 Brii_StringID::Brii_StringID(){};
 Brii_StringID::~Brii_StringID() = default;
 Brii_StringID::Brii_StringID(BT_StringID_64 stringID)
 {
  this->stringID = stringID;
 };
  Brii_StringID Brii_StringID::operator=(BT_StringID_64&& stringID) noexcept
 {
  this->stringID = stringID;
  return *this;
 }

 Brii_StringID Brii_StringID::operator=(BT_StringID_64& stringID)
 {
  this->stringID = stringID;
  return *this;
 }

 bool Brii_StringID::operator==(Brii_StringID c_stringID)
 {  
   return c_stringID.get() == stringID;
 }
 bool Brii_StringID::operator==(Brii_StringID&& c_stringID) noexcept
 {
  return c_stringID.get() == stringID;
 }
 bool Brii_StringID::operator==(const Brii_StringID& c_stringID) const
 {
  return c_stringID.stringID == stringID; 
 }
 bool Brii_StringID::operator==(BT_StringID_64&& stringID) noexcept
 {
  return this->stringID == stringID;
 }
 bool Brii_StringID::operator==(const BT_StringID_64& stringID) const
 {
  return this->stringID == stringID;
 }


 BT_StringID_64& Brii_StringID::get()
 {
  return stringID;
 }



namespace Brii_StringFNV
{
  BT_StringView trim_str(BT_StringView str)
 {
  BT_StringView_internal& str_view {str.get()};
   
  const char* characters_ws {" \t\n\r\f\v\0"};
  size_t start {str_view.find_first_not_of(characters_ws)};

  if (start == std::string_view::npos)
  {
   return str_view;
  }

  size_t end{str_view.find_last_not_of(characters_ws)};

  return str_view.substr(start, end - start + 1);
 }

 inline constexpr BT_StringID_64 hash_1a(BT_StringView str)
 {
   BT_StringView_internal& str_view {str.get()};
  
   BT_StringID_64 hash {FNV_1a_offset_basis};

   const char* str_s { str_view.data() };

   while (*str_s)
   {
     hash ^= static_cast<uint64_t>(*str_s++);
     hash *= FNV_1a_prime;
   }

   return hash;
 }

 inline constexpr BT_StringID_32 str_to_hash(BT_StringView str)
 {
//  BT_StringView_internal& str_view {str.get()};

  BT_StringView_internal str_clean {trim_str(str).get()}; //////////CONTINUE HERE, SEE WHY THROW ME DIFERENT ID WITH THE SAME STRING

  BT_StringID_32 hash {FNV_offset_basis};

  for (auto& c : str_clean)
  {
   hash ^= static_cast<uint32_t>(c);
   hash *= FNV_prime;
  }

  return hash;
 }



 constexpr BT_StringID_32 operator""_FNV_hash(const char* str, size_t len)
 {
  [[maybe_unused]] size_t lee {len};
  
  BT_String str_view {str};
 
  return str_to_hash(str_view);
 }

 
////CONTINUE HERE 31/08/2026
///Create the string manager to create a hash table saved in the RAM. ---- IN PROGRESS
//Investigate the CSV files and how to inyect them into the the string manager. ---- IN PROGRESS
//Write about this files in the documentation ---- IN PROGRESS
//Continue with the function of the creation of windows inside the SDL3_window.cpp ----IN PROGRESS

//tasks from 01/08/2026
///Write the fileSystem to encapsulate the I/O for each Operating System --- IN PROGRESS

///TASKS from 02/08/2026
///Read the instructions from Platform_Brii/Platform_FileSystem.h


}
