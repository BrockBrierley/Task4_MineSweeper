#include "Timer.h"

Timer::Timer()
{
	duration = 0;
}

int Timer::GetTime()
{
	if (activeTimer)
	{
		duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	}
	return duration;
}

void Timer::StartTimer()
{
	activeTimer = true;
	startTime = std::clock();
}

void Timer::ResetTimer()
{
	activeTimer = false;
	duration = 0;
	startTime = NULL;
}

void Timer::StopTimer()
{
	activeTimer = false;
}
