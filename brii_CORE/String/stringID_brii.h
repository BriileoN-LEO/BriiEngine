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

  //void createID_by_str(BT_String str); // NOT USE THIS | DEPRICATE

  BT_StringID_64 get() const;
};

using BT_StringID = Brii_StringID;

inline constexpr BT_StringID operator<<(const BT_StringID& str_ID, BT_StringID_64 shift_t)
{ 
 BT_StringID_64 str_copy {str_ID.get()};
 return BT_StringID(str_copy << shift_t);
}

inline constexpr BT_StringID operator>>(const BT_StringID& str_ID, BT_StringID_64 shift_t)
{
 BT_StringID_64 str_copy {str_ID.get()};
 return BT_StringID(str_copy >> shift_t);
}


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
 inline constexpr BT_StringID_32 FNV_offset_basis {2166136261u};
 inline constexpr BT_StringID_32 FNV_prime{16777619u};

 inline constexpr BT_StringID_64 FNV_1a_prime {0x100000001b3ULL};
 inline constexpr BT_StringID_64 FNV_1a_offset_basis{0xcbf29ce484222325ULL};

 ///this is dedicated for assing the domains of each string 
 inline constexpr BT_StringID_64 domain_Shift_LocStr { 56 };
 inline constexpr BT_StringID_64 HASH_MASK_64 { 0x00FFFFFFFFFFFFFFULL }; 

 BT_StringView trim_str(BT_StringView str);

 ///THIS function converts the string to an ID with the algorithm hash-1a with the domain to get the posicion
 inline constexpr BT_StringID hash_1a_domain(BT_StringView str, BT_LocStr_Flags dom)
 {
  BT_StringID_64 hash {FNV_1a_offset_basis};
  
  const char* str_Data {str.data()};
  size_t len { str.size() };

  for(size_t i = 0; i < len; i++)
  {
   hash ^= static_cast<BT_FlagsU8>(str_Data[i]);
   hash *= FNV_1a_prime;  
  }

  BT_StringID_64 domain_bits = (static_cast<BT_StringID_64>(dom) & 0xFFULL) << domain_Shift_LocStr;
  return domain_bits | (hash & HASH_MASK_64);
 };
 
 ///this function gives me the domain(category) of the loc_str that is owned the strID
 inline constexpr size_t get_idx_domain(BT_StringID* strID)
 {
  BT_StringID moveCast {*strID >> domain_Shift_LocStr};
  return static_cast<size_t>(moveCast.get());
 }


 inline constexpr BT_StringID_64 hash_1a(BT_StringView str);
 inline constexpr BT_StringID_32 str_to_hash(BT_StringView str);
 constexpr BT_StringID_32 operator""_FNV_hash(const char* str, size_t len);

}


