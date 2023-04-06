#pragma once
#include <iostream>
#include <cstdio>
#include <ctime>

class Timer
{
public:
	Timer();
	int GetTime();
	void StartTimer();
	void ResetTimer();
	void StopTimer();
protected:
	bool activeTimer = false;
	int duration = 0;
	std::clock_t startTime;
private:
};

