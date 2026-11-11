
#include "Public/Platform_Brii/Platform_Thread.h"
#include "Public/Platform_Brii/Log_System/Platform_logCalls.h"
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <immintrin.h>

struct Brii_ThreadHandle
{
 pthread_t thread {};
 //const char* debug_Name {"Brii_Worker_NotDef"};
 BT_ThreadID thread_ID{};
 call_Thread function{ nullptr }; ///the function pointer 
 void* args_data { nullptr }; //the arguments that contains the function
 uint32_t isJoinable{ false };
};

static void* thread_BridgeRoutine(void* args_ThreadHandle)
{
  Brii_ThreadHandle* thread_data {static_cast<Brii_ThreadHandle*>(args_ThreadHandle)};
  if(thread_data && thread_data->function)
  {

  //-------------------------------------------
  //Get some extra values to assing to the Thread_Handle
  thread_data->thread_ID = syscall(SYS_gettid); ///Get the ID of Thread 
  thread_data->isJoinable = true;
  ///get the state at the thread handle


   thread_data->function(thread_data->args_data);
  }
 return nullptr;
}

 void get_attr_policy(const BF_Thread::priority& attr_priority, int& shedule_policy, int& val_p)
{
   switch (attr_priority)
 {
   case BF_Thread::low_priority :
   {
     val_p = 10;
   }
  
   case BF_Thread::normal_priority :
   {
    val_p = 0;
   }

   case BF_Thread::high_priority :
   {
    val_p = -10;
   }

   case BF_Thread::realTime_priority : 
   {
    shedule_policy = SCHED_FIFO;
    val_p = 50;
   }

   case BF_Thread::backgroundBatch_priority :
   {
    shedule_policy = SCHED_BATCH;
    val_p = 0;
   } 
 }

}

static bool pthread_attr_setPriority(pthread_attr_t* p_attr, const BF_Thread::priority& attr_priority)
{
 
  if(p_attr)
 {
  int schedule_policy {SCHED_OTHER};
  sched_param param; 
 
  get_attr_policy(attr_priority, schedule_policy, param.sched_priority);

  if(pthread_attr_setschedpolicy(p_attr, schedule_policy) != 0)
  {
   return false;
  }
		
  if(pthread_attr_setschedparam(p_attr, &param) != 0)
  {
   return false;
  }
 
  return true;
 }

 return false;
}

static bool pthread_setPriority(Brii_ThreadHandle* thread_handle, const BF_Thread::priority& attr_priority)
{
  if(thread_handle != nullptr)
 {
  int schedule_policy {SCHED_OTHER};
  int prio{}; 
 
  get_attr_policy(attr_priority, schedule_policy, prio);

  pthread_setschedpolicy(thread_handle, schedule_policy);
  pthread_setschedprio(thread_handle->thread, prio); ///number of level of priority 
  //pthread_attr_setschedparam(p_attr, &param);
 
  return true;
 }

 return false;
}

static bool set_pthread_attr(pthread_attr_t* ptr_thread_attr, const Brii_ThreadDescriptor& T_description, void* args_ThreadHandle)
{
  //init the pthread_attr_t 
   if(pthread_attr_init(ptr_thread_attr) != 0)
   {
     BRII_LOG_ERROR(BF_log::thread_t, BT_String("not init attribute for thread, worker name = ") + T_description.debug_Name);
     pthread_attr_destroy(ptr_thread_attr);
     return false;
   }
  
   ///EXPLICIT TO NOT MATCH THE SAME ATTRIBUTES WITH THE PARENT THREAD, created from this thread 
   if(pthread_attr_setinheritsched(ptr_thread_attr, PTHREAD_EXPLICIT_SCHED) != 0) 
   {
     BRII_LOG_ERROR(BF_log::thread_t, BT_String("not inherit explicit sched attribute for thread, worker name = ") + T_description.debug_Name);
     pthread_attr_destroy(ptr_thread_attr);
     return false;
   }  

   ///Set the priority
   if(!pthread_attr_setPriority(ptr_thread_attr, T_description.T_priority))
   {
     BRII_LOG_ERROR(BF_log::thread_t, BT_String("not set priority attribute for thread, worker name = ") + T_description.debug_Name);
     pthread_attr_destroy(ptr_thread_attr);
     return false;
   }
   ////////////////
   //assign core affinity
   //attach thread to a cpu core
   cpu_set_t cpu_set;
   CPU_ZERO(&cpu_set);
   CPU_SET(T_description.core_AffinityIdx, &cpu_set); 
  
   if(pthread_attr_setaffinity_np(ptr_thread_attr, sizeof(cpu_set), &cpu_set) != 0)
   { 
     BRII_LOG_ERROR(BF_log::thread_t, BT_String("not set attribute Affinity of any core for thread, worker name = ") + T_description.debug_Name);
     pthread_attr_destroy(ptr_thread_attr);
     return false;
   } 

   //assign stack size
   if(pthread_attr_setstacksize(ptr_thread_attr, T_description.stack_Size) != 0)
   {
     BRII_LOG_ERROR(BF_log::thread_t, BT_String("not set attribute stack size for thread, worker name = ") + T_description.debug_Name);
     pthread_attr_destroy(ptr_thread_attr);
     return false;
   }
   
    if(pthread_attr_setdetachstate(ptr_thread_attr, PTHREAD_CREATE_JOINABLE) != 0)
   {
    BRII_LOG_ERROR(BF_log::thread_t, BT_String("not set attribute stack size for thread, worker name = ") + T_description.debug_Name);
    pthread_attr_destroy(ptr_thread_attr);
    return false;
   }
 //Stack address = leave this option for future optimizations | if is implement, POSIX will disable Guard Size and it could make corrupt memoria cruzada
 //Guard Size = leave it, not change | could cause Stack Overflow, is a page of virtual memory at the end of the thread memory.
 return true;
}



 Brii_Thread::Brii_Thread(Brii_Thread&& _T) noexcept
 {
  Thread_Handle = std::move(_T.Thread_Handle); 
  _T.Thread_Handle = nullptr;
  delete _T.Thread_Handle;
 }

 Brii_Thread& Brii_Thread::operator=(Brii_Thread&& _T) noexcept
{
 if(Thread_Handle != nullptr)
 {
  ///Here put the destructor of the thread to elimintate the routine of the thread  
 }

 Thread_Handle = std::move(_T.Thread_Handle); 
 _T.Thread_Handle = nullptr;
 delete _T.Thread_Handle;
 return *this;
}

 void Brii_Thread::initialize(const Brii_ThreadDescriptor& T_description, call_Thread T_call, void* args_ThreadHandle)
{ 
 if(T_call && args_ThreadHandle)
 {
  
  pthread_attr_t ptr_thread_attr {};

  bool attr_attach {T_description.attr_available == 1 ? true : false};
  bool attr_implement { false };
   
   if(attr_attach)
  { 
   attr_implement = set_pthread_attr(&ptr_thread_attr, T_description, args_ThreadHandle);
  }

  int tc { pthread_create(
      &Thread_Handle->thread, 
      attr_implement ? &ptr_thread_attr : nullptr, 
      &thread_BridgeRoutine, 
      args_ThreadHandle
  )};

  if(tc != 0)
  { 
   BRII_LOG_ERROR(BF_log::job_schedule_t, BT_String("thread not created, Worker name = ") + T_description.debug_Name);
  }

  else if(tc == 0)
  {
   BRII_LOG_INFO(BF_log::job_schedule_t, BT_String("Initialize Thread Worker, Worker name = ") + T_description.debug_Name);
  }

  pthread_attr_destroy(&ptr_thread_attr);
 }

  BRII_LOG_ERROR(BF_log::job_schedule_t, BT_String("not initialize thread, Worker name = ") + T_description.debug_Name);
}

 bool Brii_Thread::is_joinable()
 {
  return static_cast<bool>(Thread_Handle->isJoinable);
 }

 void Brii_Thread::join()
 {
  if(Thread_Handle == nullptr)
 {
  BRII_LOG_ERROR(BF_log::thread_t, BT_String("not initialize thread")); 
  return;
 }
 
   void* thread_result { nullptr };
   if(pthread_join(Thread_Handle->thread, &thread_result) != 0)
   {
    BRII_LOG_ERROR(BF_log::thread_t, BT_String("not join thread, thread ID = ") + BTL::toString(Thread_Handle->thread_ID));
   }

  ///here send this result of the join to the job_schedule
  int* tResult_ptr { reinterpret_cast<int*>(thread_result) }; 
 
 }

 void Brii_Thread::detach() const noexcept
 {  
   if(Thread_Handle == nullptr)
  {
   BRII_LOG_ERROR(BF_log::thread_t, BT_String("not initialize thread")); 
   return;
  }

   if(pthread_detach(Thread_Handle->thread) != 0)
   {
    BRII_LOG_ERROR(BF_log::thread_t, BT_String("not detach thread, thread ID = ") + BTL::toString(Thread_Handle->thread_ID));
   }
 }

 bool Brii_Thread::set_CoreAffinity(BT_ThreadCore core_idx)
{
 if(Thread_Handle != nullptr)
 {
   cpu_set_t cpu_set;
   CPU_ZERO(&cpu_set);
   CPU_SET(core_idx, &cpu_set); 
  
   if(pthread_setaffinity_np(Thread_Handle->thread, sizeof(cpu_set), &cpu_set) != 0)
   { 
     BRII_LOG_ERROR(BF_log::thread_t, BT_String("not set attribute Affinity of any core for thread, thread ID = ") + BTL::toString(Thread_Handle->thread_ID));
     return false;
   }
  
  return true;
 }

 return false;
}

 bool Brii_Thread::set_Priority(BF_Thread::priority thread_priority)
{

}
 BT_ThreadID Brii_Thread::get_threadID() const noexcept
{

}
 const Brii_ThreadHandle* Brii_Thread::get_NativeHandle() const noexcept
{

}

 ///CONTINUE HERE TO FINISH THE THREAD ABSTRACTION
 
namespace BTL
{

  void ThisThread::Yiels_exec() noexcept
 {

 }
  void ThisThread::Cpu_pause() noexcept
 {
  _mm_pause();
 }
 
  void ThisThread::sleepFor(BTL::timer::nanoseconds time_milliseconds) noexcept
 {
   struct timespec ts;
	
   ts.tv_sec = BTL::timer::duration_convertion<BTL::timer::seconds>(time_milliseconds).count();
  
   ts.tv_nsec = time_milliseconds.count() % 1000000000;

   nanosleep(&ts, nullptr);
 } 
  
 BT_ThreadID ThisThread::getCurrentThreadID() noexcept
 { 
  return syscall(SYS_gettid);
 }
  
 BT_ThreadCore ThisThread::getPhysicalCoreCount() noexcept
 { 
  BT_ThreadCore cpu_cores {sysconf(_SC_NPROCESSORS_ONLN)}; 
  
  if(cpu_cores == -1)
  {
   BRII_LOG_ERROR(BF_log::thread_t, "unable to get Physical cores count");  
   ///HERE THROW AN ERROR, close all the systems that are working
   return 0;
  }
	 
  return cpu_cores;
 }

}

