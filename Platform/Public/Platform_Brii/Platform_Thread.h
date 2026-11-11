#pragma once

#include "Settings/Settings_Thread.h"
#include "Settings/Settings_Time.h"
#include "dataManager/dataTypes_brii.h"

struct Brii_ThreadHandle;

using call_Thread = void(*)(void* args);

 ///THIS DESCRIPTOR IS USED FOR THE WORKERS IN THE Job_Schedule
struct Brii_ThreadDescriptor
{
 const char* debug_Name {"Brii_Worker_NotDef"}; ///This name is from the name of worker in Job Schedule 
 size_t stack_Size {};
 uint32_t core_AffinityIdx{0xFFFFFFFF};
 BF_Thread::priority T_priority { BF_Thread::normal_priority };
 uint8_t attr_available{ 0 }; ///0 == FALSE | 1 == TRUE | NO MORE
 /// Points to consider:
 /// -if attr_available is false, the thread will be inheritaded the properties of the parent thread or the thread that creates this thread.
 ///
};

class alignas(64) Brii_Thread
{
 private: 
 
 Brii_ThreadHandle* Thread_Handle{nullptr};

 public:

 Brii_Thread(Brii_Thread&& _T) noexcept;
 Brii_Thread& operator=(Brii_Thread&& _T) noexcept;
 
 Brii_Thread(const Brii_Thread& _T) = delete;
 Brii_Thread& operator=(Brii_Thread& _T) = delete;

 void initialize(const Brii_ThreadDescriptor& T_des, call_Thread T_call, void* args);
 bool is_joinable();
 void join();
 void detach() const noexcept;

 bool set_CoreAffinity(BT_ThreadCore core_idx);
 bool set_Priority(BF_Thread::priority thread_priority);
 BT_ThreadID get_threadID() const noexcept;
 const Brii_ThreadHandle* get_NativeHandle() const noexcept;
 
};

namespace BTL
{
  namespace ThisThread
 {
  void Yiels_exec() noexcept;
  void Cpu_pause() noexcept;
  void sleepFor(BTL::timer::nanoseconds time_milliseconds) noexcept;
  BT_ThreadID getCurrentThreadID() noexcept;
  BT_ThreadCore getPhysicalCoreCount() noexcept;
 }

}

//////CONTINUE HERE FOR THE CREATION OF THE ABSTRACTION OF THREADS

