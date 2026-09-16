#pragma once

#include <iostream>


  ///THIS STRUCT is used to transport this log_files
  template<typename T>
  class Brii_port_voidPtr
 {
   private:

   void* log_f{};
   using idx_t = T;

   public: 
   Brii_port_voidPtr(){};

   inline void insert_log_f(idx_t* log_f)
   {
     this->log_f = static_cast<void*>(log_f);
   }
 
   inline idx_t* get_LogFile_w()
   {
     return static_cast<idx_t*>(log_f);
   }

   inline void clear()
   {
    log_f = nullptr; 
   } 
   
 };
