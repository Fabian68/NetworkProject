#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <chrono>
using namespace std;

class Clock
{
public :
	Clock(int hourStart = 0);
	void start();
	string toString();
	double time();
	void stop();
private :
	chrono::duration<double> _totalTime;
	chrono::steady_clock::time_point _startedTime;
};

#endif