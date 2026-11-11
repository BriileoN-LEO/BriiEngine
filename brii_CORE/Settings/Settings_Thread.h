#pragma once

#include <pthread.h>
#include <iostream>


enum class Brii_Thread_Priority : uint8_t
{
 LOW = 0,
 NORMAL = 1,
 HIGH = 2,
 REAL_TIME = 3,
 BACKGROUND_BATCH = 4
};

namespace BF_Thread
{
 
 using priority = Brii_Thread_Priority;

 inline constexpr priority low_priority = priority::LOW;
 inline constexpr priority normal_priority = priority::NORMAL;
 inline constexpr priority high_priority = priority::HIGH;
 inline constexpr priority realTime_priority = priority::REAL_TIME;
 inline constexpr priority backgroundBatch_priority = priority::BACKGROUND_BATCH;
}
