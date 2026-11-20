#pragma once 

#include "dataManager/dataTypes_brii.h" 
#include "Settings/Settings_JobSystem.h"
#include "Public/Platform_Brii/Platform_Thread.h"
///Testing tips and thicks of CONCURRENCY


namespace brii
{

struct alignas(64) JobDeclaration
{
 brii::ThreadDescriptor task_info{};
 brii::func_call func{};
 void* args_data;
};

struct JobWorker
{
 brii::Thread thread_worker{};

};


class JobSystem
{
 private:
 
 std::vector<JobWorker> worker_System{}; ///CHANGE for a free-lock thread queue

  
 ///CONTINUE HERE to implement the JobSchedule  
 
  

 public: 

 //void testing_only{};

};


}
