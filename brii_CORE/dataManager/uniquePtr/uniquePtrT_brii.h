
#pragma once

#include <memory>
#include <utility>

template<typename T>
using BT_uniquePtr_internal = std::unique_ptr<T>;


template<typename T, typename... Args>
class brii_uniquePtrType
{
 private:

 BT_uniquePtr_internal<T> uniquePtr{};

 public:

 ///TRANSFARE THE UNIQUE POINTER
// brii_uniquePtrType() = default;
  ///BUILDING THE TYPE UNIQUE POINTER BY ARGUMENTS
 brii_uniquePtrType(Args&&... args)
 {
  uniquePtr = std::make_unique<T>(T(std::forward<Args>(args)...));
 } 
 brii_uniquePtrType(brii_uniquePtrType&& var) noexcept
 { 
  uniquePtr = std::move(var.uniquePtr);
  var.clear();
 }
 brii_uniquePtrType(brii_uniquePtrType& var)
 {
  uniquePtr = std::move(var.uniquePtr);
  var.clear();
 }

 ///IF IS ONLY PASS THE TYPE
 brii_uniquePtrType(T&& var) noexcept
 {
  uniquePtr = std::make_unique<T>(var);
 }
 brii_uniquePtrType(T& var)
 { 
  uniquePtr = std::make_unique<T>(var);
 }
 
 ~brii_uniquePtrType() = default;

 brii_uniquePtrType operator=(brii_uniquePtrType&& var) noexcept
 {
  uniquePtr = std::move(var.uniquePtr);
 }
 brii_uniquePtrType operator=(brii_uniquePtrType& var)
 {
  uniquePtr = std::move(var.uniquePtr);
  var.clear();
 }
 brii_uniquePtrType operator=(T&& var) noexcept
 {
   uniquePtr = std::make_unique<T>(var);
 }
 brii_uniquePtrType operator=(T& var)
 {
  uniquePtr = std::make_unique<T>(var);
 }

 T* operator->() const
 {
  return uniquePtr.get();
 }


 T* get() const
 {
   return uniquePtr.get();
 }

 void clear() const 
 {
  uniquePtr = nullptr;
 }
};

template<typename T>
using BT_uniquePtr_btl = brii_uniquePtrType<T>;

namespace BTL
{
 template<typename T, typename... Args>
 BT_uniquePtr_btl<T> make_unique(Args&&... args)
 {
  return BT_uniquePtr_btl<T>(T(std::forward<Args>(args)...)); ///THIS FUNCTIONS LINKS with the constnuctor of args in unique ptr brii 
 }

 template<typename T>
  BT_uniquePtr_btl<T> make_unique(T&& var)
 {
  return BT_uniquePtr_btl<T>(var); 
 }

 template<typename T>
  BT_uniquePtr_btl<T> make_unique(T& var)
 {
  return BT_uniquePtr_btl<T>(var); 
 }

  template<typename T>
  BT_uniquePtr_btl<T> make_unique(T var)
 {
  return BT_uniquePtr_btl<T>(var); 
 }

}





