#pragma once

#include <iostream>


  ///THIS STRUCT is used to transport this log_files
  template<typename T>
  class Brii_port_voidPtr
 {
   private:

   void* log_f{};

   public: 
   Brii_port_voidPtr(){};

   inline void insert_log_f(T* log_f)
   {
     this->log_f = static_cast<void*>(log_f);
   }
 
   inline T* get_LogFile_w()
   {
     return static_cast<T*>(log_f);
   }

   inline void clear()
   {
    log_f = nullptr; 
   } 
   
 };
