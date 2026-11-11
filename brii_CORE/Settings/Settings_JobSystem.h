
#include <iostream>

enum class Brii_JobSystem_queues : uint8_t
{
 LOW = 0,
 NORMAL = 1,
 HIGH_PRIORITY = 2
};


namespace BF_JobSys
{ 

using queues = Brii_JobSystem_queues;
inline constexpr queues low_job = queues::LOW;
inline constexpr queues normal_job = queues::NORMAL;
inline constexpr queues high_priority_job = queues::HIGH_PRIORITY;

}


