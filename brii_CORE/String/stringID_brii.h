#pragma once

#include "dataManager/dataTypes_brii.h"


class Brii_StringID
{
  private:
  BT_StringID_64 stringID{}; 
  
  public:
  Brii_StringID();
  ~Brii_StringID();
  Brii_StringID(BT_String str);
  Brii_StringID(BT_StringID_64 stringID);
  Brii_StringID operator=(BT_StringID_64&& stringID) noexcept;
  Brii_StringID operator=(BT_StringID_64& stringID);
 
  bool operator==(Brii_StringID c_stringID);
  bool operator==(Brii_StringID&& c_stringID) noexcept;
  bool operator==(const Brii_StringID& c_stringID) const;
  bool operator==(BT_StringID_64&& stringID) noexcept;
  bool operator==(const BT_StringID_64& stringID) const;

  void createID_by_str(BT_String str);

  BT_StringID_64& get();
};

using BT_StringID = Brii_StringID;

///this hash makes a cusmtom key from the BT_StringID
///used by the BT_HashTable to create a custom container
struct hash_BT_StringID
{ 
 std::size_t operator()(BT_StringID key) const
 {
  return key.get() ^ 0xBEEAFCDBFE;
 }; 
};

namespace Brii_StringFNV
{
 static constexpr BT_StringID_32 FNV_offset_basis {2166136261u};
 static constexpr BT_StringID_32 FNV_prime{16777619u};

 static constexpr BT_StringID_64 FNV_1a_prime {0x100000001b3ULL};
 static constexpr BT_StringID_64 FNV_1a_offset_basis{0xcbf29ce484222325ULL};

 BT_StringView trim_str(BT_StringView str);

 inline constexpr BT_StringID_64 hash_1a(BT_StringView str);

 inline constexpr BT_StringID_32 str_to_hash(BT_StringView str);

 constexpr BT_StringID_32 operator""_FNV_hash(const char* str, size_t len);

}


