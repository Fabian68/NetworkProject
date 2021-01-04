#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

struct duration {
	chrono::duration<double> numberOfTicks;
	double speedModifier;
};

class Clock
{
public :
	Clock(int secondStart = 0, int speedMultiplier = 1); // Constructor
	int start(); // Start the timer
	string toString(); // Obtain a string of the current time
	double time(); // Get a double value of the time in seconds
	int stop(); // Stop the timer
	int changeSpeed(double multiplier); // Change the speed multiplier of the timer
	void reset(); // Reset the time of the timer to 0
private :
	chrono::duration<double> _totalTime;
	chrono::steady_clock::time_point _startedTime;
	double _secondsInOneTick;
	bool _clockOngoing;
	vector<duration> _tabDuration;
};

#endif