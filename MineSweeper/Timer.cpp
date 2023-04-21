#include "Timer.h"

/// <summary>
/// timer constructor, sets the current duration to 0
/// </summary>
Timer::Timer()
{
	duration = 0;
}

/// <summary>
/// gets the current time recorded
/// </summary>
/// <returns></returns>
int Timer::GetTime()
{
	//check if the timer is active
	if (activeTimer)
	{
		//calculate how long the timer has been active
		duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	}
	//return how long the timer is active
	return duration;
}

/// <summary>
/// start the timer
/// </summary>
void Timer::StartTimer()
{
	//start the timer
	activeTimer = true;
	
	//get the current time on the system clock
	startTime = std::clock();
}

/// <summary>
/// reset the timer back to 0
/// </summary>
void Timer::ResetTimer()
{
	//deactivate the timer
	activeTimer = false;
	//resets how long the timer has been active
	duration = 0;
	//resets the start time
	startTime = NULL;
}

/// <summary>
/// stops the timer without resetting the duration
/// </summary>
void Timer::StopTimer()
{
	//stop the timer
	activeTimer = false;
}
