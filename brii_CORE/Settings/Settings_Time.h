#include <chrono>

namespace BTL
{
  namespace timer
 { 

  template<typename Rep, typename Period>
  using timer_duration = std::chrono::duration<Rep, Period>;

  template<typename _Tp>
      struct is_timer_duration
      : std::false_type
      { };
 
  ////IF IS TIMER DURATION
  template<typename _Rep, typename _Period>
      struct is_timer_duration<timer_duration<_Rep, _Period>>
      : std::true_type
      { };

  template<typename _Tp>
      using enable_if_is_timer_duration
	= typename std::enable_if<is_timer_duration<_Tp>::value, _Tp>::type;
 

  using seconds = std::chrono::seconds;
  using microseconds = std::chrono::microseconds;
  using nanoseconds = std::chrono::nanoseconds;

  
 template<typename Dur, typename Rep, typename Period>
 constexpr enable_if_is_timer_duration<Dur> 
  duration_convertion(const timer_duration<Rep, Period>& time_count)
 {
  return std::chrono::duration_cast<Dur>(time_count);
 }
 

 }

}
