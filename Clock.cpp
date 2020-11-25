#include "Clock.h"
#include <sstream>

/**
* Can't add minutes when considering 1 tick to be 1 hour so secondStart has to be higher than howManySecondsInOneTick
*/
Clock::Clock(int secondStart, int howManySecondsInOneTick) : _startedTime{}, _secondsInOneTick{ howManySecondsInOneTick }, _clockOngoing{false}
{
	_totalTime = chrono::seconds(secondStart / howManySecondsInOneTick);
}

void Clock::start()
{
	_startedTime = chrono::steady_clock::now();
	_clockOngoing = true;
}

string Clock::toString()
{
	if (_clockOngoing == true) 
	{
		chrono::steady_clock::time_point tempTime = chrono::steady_clock::now();
		chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(tempTime - _startedTime);
		chrono::duration<double> temporaryTime = time_span + _totalTime;
		int timespan = temporaryTime.count();
		int seconde = timespan % 86400 * _secondsInOneTick;
		int hour = (seconde / 3600);
		int minute = (seconde % 3600) / 60;
		string toString = std::to_string(hour) + " heures, " + std::to_string(minute) + " minutes, " + std::to_string(seconde) + " secondes";
		return toString;
	}
	else 
	{
		int timespan = _totalTime.count();
		int seconde = timespan % 86400 * _secondsInOneTick;
		int hour = (seconde / 3600);
		int minute = (seconde % 3600) / 60;
		string toString = std::to_string(hour) + " heures, " + std::to_string(minute) + " minutes, " + std::to_string(seconde) + " secondes";
		return toString;
	}
}

double Clock::time()
{
	if (_clockOngoing == true)
	{
		chrono::steady_clock::time_point tempTime = chrono::steady_clock::now();
		chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(tempTime - _startedTime);
		chrono::duration<double> temporaryTime = time_span + _totalTime;
		int timespan = temporaryTime.count();
		return timespan % 86400 * _secondsInOneTick;
	}
	else
	{
		int timespan = _totalTime.count();
		return timespan % 86400 * _secondsInOneTick;
	}
}

void Clock::stop()
{
	chrono::steady_clock::time_point endedTime = chrono::steady_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(endedTime - _startedTime);
	_totalTime += time_span;
	_clockOngoing = false;
}
