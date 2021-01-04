#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <chrono>
using namespace std;

class Clock
{
public :
	Clock(int secondStart = 0, int howManySecondsInOneTick = 60);
	void start();
	string toString();
	double time();
	void stop();
private :
	chrono::duration<double> _totalTime;
	chrono::steady_clock::time_point _startedTime;
	int _secondsInOneTick;
	bool _clockOngoing;
};

#endif