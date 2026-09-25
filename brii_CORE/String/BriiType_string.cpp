#include "BriiType_string.h"

 Brii_TypeString::Brii_TypeString(){};
// Brii_TypeString::Brii_TypeString(const char* TChar)
 //{ 
  // Tstring = TChar; 
 //}
 Brii_TypeString::Brii_TypeString(Brii_TypeString&& Tstring_c) noexcept
 {
  this->Tstring = Tstring_c.Tstring;
 }
 Brii_TypeString::Brii_TypeString(const Brii_TypeString& Tstring_c)
 { 
  this->Tstring = Tstring_c.Tstring;
 }
 Brii_TypeString::Brii_TypeString(const BT_string_internal& Tstring_in)
 {
  this->Tstring = Tstring_in;
 }

 /////////////convertion of integrals to strings/////////////
 Brii_TypeString::Brii_TypeString(uint32_t&& n) noexcept
 {
  this->Tstring = std::to_string(n);
 }

 Brii_TypeString::Brii_TypeString(uint32_t& n)
 {
  this->Tstring = std::to_string(n);
 }

 Brii_TypeString::Brii_TypeString(uint32_t n)
 {
  this->Tstring = std::to_string(n);
 }

 Brii_TypeString Brii_TypeString::operator=(const Brii_TypeString Tstring_c)
 {
  this->Tstring = Tstring_c.Tstring;
  return *this;
 }
 
 Brii_TypeString Brii_TypeString::operator+=(Brii_TypeString&& Tstring_c)
 {
  this->Tstring += *Tstring_c.get_TypeString();
  return *this;
 }

 Brii_TypeString Brii_TypeString::operator+=(const BT_string_internal&& Tstring_c)
 {
  this->Tstring += Tstring_c;
  return *this;
 }

 Brii_TypeString Brii_TypeString::operator+=(const char* Tstring_c)
 {
  this->Tstring += BT_string_internal(Tstring_c);
  return *this;
 }
 
 Brii_TypeString Brii_TypeString::combine_operator_out(Brii_TypeString& Tstring_c)
 {
   BT_string_internal* tS_in = Tstring_c.get_TypeString();
   BT_string_internal Tstring_out { Tstring + *tS_in }; 
 
  return Brii_TypeString(Tstring_out);
 }

 void Brii_TypeString::combine_operator_in(Brii_TypeString& Tstring_c)
 {
  this->Tstring += *Tstring_c.get_TypeString();
 } 

  const char* Brii_TypeString::operator*() 
 {
  return Tstring.c_str();
 }

 
 const char* Brii_TypeString::Tchar_ptr()
 {
  return Tstring.c_str();  	
 } 
  

 constexpr BT_string_internal* Brii_TypeString::get_TypeString()
 {
  return &Tstring;
 }

 Brii_TypeString operator+(Brii_TypeString TS_x, Brii_TypeString TS_y)
 {
  return TS_x.combine_operator_out(TS_y);
 }

 Brii_TypeString operator+(const char* Tchar_ptr, Brii_TypeString TypeString)
 {
  return Brii_TypeString(Tchar_ptr) + TypeString;
 } 
 Brii_TypeString operator+(Brii_TypeString TypeString, const char* Tchar_ptr)
 {
  return TypeString + Brii_TypeString(Tchar_ptr); 
 }

 Brii_TypeString operator<<(Brii_TypeString TS_x, const char* Tchar_ptr)
 {
  return TS_x + Brii_TypeString(Tchar_ptr);
 }
 Brii_TypeString operator<<(const char* Tchar_ptr, Brii_TypeString TS_x)
 {
  return Brii_TypeString(Tchar_ptr) + TS_x;
 }
 Brii_TypeString operator<<(Brii_TypeString TS_x, Brii_TypeString TS_y)
 {
  return TS_x + TS_y;
 }
  
 Brii_TypeStringView::Brii_TypeStringView(){};
 
 Brii_TypeStringView::Brii_TypeStringView(Brii_TypeString& T_String)
 {
  this->T_StringView = *T_String.get_TypeString();
 }

 Brii_TypeStringView::Brii_TypeStringView(BT_string_internal& T_String)
 {
  this->T_StringView = T_String; 
 }

 Brii_TypeStringView::Brii_TypeStringView(BT_StringView_internal&& T_StringViewIn) noexcept
 {
  this->T_StringView = T_StringViewIn;
 }
 Brii_TypeStringView::Brii_TypeStringView(BT_StringView_internal& T_StringViewIn)
 {
  this->T_StringView = T_StringViewIn;
 }
 Brii_TypeStringView::Brii_TypeStringView(Brii_TypeStringView& T_stringView)
 {
  this->T_StringView = T_stringView.get();
 }
 Brii_TypeStringView::Brii_TypeStringView(const char* Tchar_view)
 {
  this->T_StringView = Tchar_view; 
 }
 Brii_TypeStringView::~Brii_TypeStringView() = default;

 BT_StringView_internal& Brii_TypeStringView::get()
 {
  return T_StringView;
 }

 const char* Brii_TypeStringView::data()
 {
  return T_StringView.data(); 
 }



