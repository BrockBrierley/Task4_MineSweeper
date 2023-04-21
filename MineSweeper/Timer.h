#pragma once
#include <iostream>
#include <cstdio>
#include <ctime>

class Timer
{
public:
	//constructor
	Timer();
	//return the current recorded time
	int GetTime();
	//starts the timer
	void StartTimer();
	//resets the timer
	void ResetTimer();
	//stops the timer
	void StopTimer();
protected:
private:
	//timer state, active or not
	bool activeTimer = false;
	//int to store the time while the timer is active
	//required to be able to stop the timing and still display the timer
	//does not allow for pausing and continueing the timer but is not necessary in this game
	int duration = 0;
	//stores the start time for the timer
	std::clock_t startTime;
};

