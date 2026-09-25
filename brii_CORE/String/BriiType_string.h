#pragma once 

#include <iostream>
#include <string>

//This class works like an abstraction of what it the string can do
//
//POINTS TO CONSIDERED FOR WHY IS MADE THIS CLAS
//-The convertion functions of std::string to const char* could difered from other libraries if in the future i will change the std::string type
//
//It will saved in dataTypes_brii.h to consult like BT_String

using BT_string_internal = std::string;
using BT_StringView_internal = std::string_view;

class Brii_TypeString
{
 private:

 BT_string_internal Tstring{};
 
 public:

 Brii_TypeString();
 //Brii_TypeString(const char* TChar);
 Brii_TypeString(Brii_TypeString&& Tstring_c) noexcept;
 Brii_TypeString(const Brii_TypeString& Tstring_c);
 Brii_TypeString(const BT_string_internal& Tstring_in);

 Brii_TypeString(uint32_t&& n) noexcept;
 Brii_TypeString(uint32_t& n);
 Brii_TypeString(uint32_t n);
 
 ~Brii_TypeString() = default;

 constexpr Brii_TypeString(const char* TChar)
 {
  Tstring = TChar;
 }

 Brii_TypeString operator=(const Brii_TypeString Tstring_c);

 Brii_TypeString operator+=(Brii_TypeString&& Tstring_c);
 Brii_TypeString operator+=(const BT_string_internal&& Tstring_c);
 Brii_TypeString operator+=(const char* Tstring_c); 
 
 
 Brii_TypeString combine_operator_out(Brii_TypeString& Tstring_c);///IT RETURNS a COPY of the Tstring combined with Tstring_c
 void combine_operator_in(Brii_TypeString& Tstring_c);//IT combines the internal BT_string_internl Tstring

 const char* operator*(); ///operator to overload the original meaning of pointers, in this case it will be return the const char* from the Tstring
 
 const char* Tchar_ptr(); //DIRECT POINTER WITHOUT ANY CONVERTED TYPE OF ANSI OR UNICODE(UTF-8)
 
 constexpr BT_string_internal* get_TypeString();
};

 Brii_TypeString operator+(Brii_TypeString TS_x, Brii_TypeString TS_y); 
 Brii_TypeString operator+(const char* Tchar_ptr, Brii_TypeString TypeString);
 Brii_TypeString operator+(Brii_TypeString TypeString, const char* Tchar_ptr);

 Brii_TypeString operator<<(Brii_TypeString TS_x, const char* Tchar_ptr);
 Brii_TypeString operator<<(const char* Tchar_ptr, Brii_TypeString TS_x);
 Brii_TypeString operator<<(Brii_TypeString TS_x, Brii_TypeString TS_y); 
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class Brii_TypeStringView
{
 private:
 BT_StringView_internal T_StringView{};
 
 public:

 Brii_TypeStringView();
 Brii_TypeStringView(Brii_TypeString& T_String);
 Brii_TypeStringView(BT_string_internal& T_String);
 Brii_TypeStringView(BT_StringView_internal&& T_StringViewIn) noexcept;
 Brii_TypeStringView(BT_StringView_internal& T_StringViewIn);
 Brii_TypeStringView(Brii_TypeStringView& T_stringView);
 Brii_TypeStringView(const char* Tchar_view);
  
 ~Brii_TypeStringView();

 BT_StringView_internal& get();
 const char* data();


};


///10/09/2026
///Complete this functions to make a convertion encode of BT_string_global
//Brii_TypeString ConvertTo_ANSI(const Brii_TypeString& B_TString);
//Brii_TypeString ConvertTo_UTF8(const Brii_TypeString& B_TString);



