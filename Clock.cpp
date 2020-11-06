#include "Clock.h"

Clock::Clock(int hourStart) : _startedTime{}
{
	_totalTime = chrono::seconds(0);
	_totalTime += chrono::seconds(hourStart);
}

void Clock::start()
{
	_startedTime = chrono::steady_clock::now();
}

string Clock::toString()
{
	chrono::steady_clock::time_point tempTime = chrono::steady_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(tempTime - _startedTime);
	chrono::duration<double> temporaryTime = _totalTime + time_span;
	int timespan = temporaryTime.count();
	int seconde = timespan % 86400 * 60;
	int hour = seconde / 3600;
	int minute = (seconde % 3600) / 60;
	string toString = hour + "h";
	toString += minute + "minutes";
	return toString;
}

double Clock::time()
{
	chrono::steady_clock::time_point tempTime = chrono::steady_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(tempTime - _startedTime);
	chrono::duration<double> temporaryTime = _totalTime + time_span;
	int timespan = temporaryTime.count();
	return timespan % 86400 * 60;
}

void Clock::stop()
{
	chrono::steady_clock::time_point endedTime = chrono::steady_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(endedTime - _startedTime);
	_totalTime += time_span;
}
