
#pragma once

#include <memory>
#include <utility>

template<typename T>
using BT_uniquePtr_internal = std::unique_ptr<T>;


template<typename T, typename... Args>
class brii_uniquePtrType
{
 private:

 //BT_uniquePtr_internal<T> uniquePtr;

 T* uniquePtr;

 public:

 explicit brii_uniquePtrType() : uniquePtr(nullptr){};
 explicit brii_uniquePtrType(std::nullptr_t) : uniquePtr(nullptr){};

 explicit brii_uniquePtrType(T* varPtr) : uniquePtr(varPtr){}; 

  ~brii_uniquePtrType()
 {
   if(uniquePtr != nullptr)
  {
   clear();
  }
 };

 //brii_uniquePtrType(const T&& var) noexcept = delete;
 brii_uniquePtrType(const T& var) = delete;
  
 brii_uniquePtrType& operator=(brii_uniquePtrType& var) = delete;
 brii_uniquePtrType& operator=(brii_uniquePtrType&& var) noexcept
 {
  if(this != &var)
  {
    if(uniquePtr != nullptr)
   {
    clear(); 
   }

   uniquePtr = var.uniquePtr;
   var.uniquePtr = nullptr;
    
  }
   
  return *this;
 }

 T* operator->() const
 {
  return uniquePtr;
 }
 T& operator*() const
 {
  return &uniquePtr;
 }

 T* get() const
 {
   return uniquePtr;
 }

 void clear() const 
 {
  delete uniquePtr;
 }
};

template<typename T>
using BT_uniquePtr_btl = brii_uniquePtrType<T>;

namespace BTL
{

 template<typename T, typename... Args>
 //requires (std::is_lvalue_reference_v<Args> && ...)
 BT_uniquePtr_btl<T> make_unique(Args&&... args)
 {
  return BT_uniquePtr_btl<T>(new T(std::forward<Args>(args)...)); ///THIS FUNCTIONS LINKS with the constructor of args in unique ptr brii 
 }

 template<typename T>
 requires std::is_rvalue_reference_v<T> ///&&
  BT_uniquePtr_btl<T> make_unique(T var)
 {
  return BT_uniquePtr_btl<T>(new T(var)); 
 }

 template<typename T, typename... Args> ///&
 requires std::is_lvalue_reference_v<T>
  BT_uniquePtr_btl<T> make_unique(T var)
 {
  return BT_uniquePtr_btl<T>(new T(var)); 
 }

 template<typename T>
 requires (!std::is_reference_v<T> && !std::is_pointer_v<T>) ///nothing 
 BT_uniquePtr_btl<T> make_unique(T var)
 {
  return BT_uniquePtr_btl<T>(new T(var)); 
 }

}





