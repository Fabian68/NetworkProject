#include "Clock.h"
#include <sstream>

/**
* Constructor of clock; Use secondStart to increase the timer without launching it, and speedMultiplier to put a specific speed
*/
Clock::Clock(int secondStart, int speedMultiplier) : _startedTime{},  _clockOngoing{false}
{
	if (speedMultiplier < 0 || speedMultiplier>3600) {
		speedMultiplier = 1;
	}
	double tmpDouble = speedMultiplier * 60 * 1.0;
	_secondsInOneTick = tmpDouble;
	_totalTime = chrono::seconds(secondStart / speedMultiplier);
	duration tmp = { _totalTime, speedMultiplier };
	_tabDuration.push_back(tmp);
}

//Return a 0 if the timer is already started, and 1 if the timer has started
int Clock::start()
{
	if (_clockOngoing == false) {
		_startedTime = chrono::steady_clock::now();
		_clockOngoing = true;
		return 1;
	}
	else {
		return 0;
	}
}

// Return a string containing the number of hours, minutes and seconds in the timer
string Clock::toString()
{
	if (_clockOngoing == true) 
	{
		chrono::steady_clock::time_point tempTime = chrono::steady_clock::now();
		chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(tempTime - _startedTime);
		int timespanTemp = time_span.count();

		int duration = 0;
		for (int i = 0; i < _tabDuration.size(); ++i)
		{
			int timeSpan = _tabDuration[i].numberOfTicks.count();
			duration += timeSpan % 86400 * _tabDuration[i].speedModifier;
		}

		timespanTemp = timespanTemp % 86400;
		int seconde = timespanTemp * _secondsInOneTick + duration;
		int hour = (seconde / 3600);
		int minute = (seconde % 3600) / 60;
		seconde = seconde - (3600 * hour) - (60 * minute);
		string toString = std::to_string(hour) + " heures, " + std::to_string(minute) + " minutes, "  + std::to_string(seconde) + " seconds" ;
		return toString;
	}
	else 
	{
		int duration = 0;
		for (int i = 0; i < _tabDuration.size(); ++i)
		{
			int timeSpan = _tabDuration[i].numberOfTicks.count();
			duration += timeSpan % 86400 * _tabDuration[i].speedModifier;
		}

		int seconde = duration;
		int hour = (seconde / 3600);
		int minute = (seconde % 3600) / 60;
		seconde = seconde - (3600 * hour) - (60 * minute);
		string toString = std::to_string(hour) + " heures, " + std::to_string(minute) + " minutes, " +  std::to_string(seconde) + " seconds";
		return toString;
	}
}

// Return a double value with the time in seconds
double Clock::time()
{
	if (_clockOngoing == true)
	{
		chrono::steady_clock::time_point tempTime = chrono::steady_clock::now();
		chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(tempTime - _startedTime);
		int timespanTemp = time_span.count();

		int duration = 0;
		for (int i = 0; i < _tabDuration.size(); ++i)
		{
			int timeSpan = _tabDuration[i].numberOfTicks.count();
			duration += timeSpan % 86400 * _tabDuration[i].speedModifier;
		}

		timespanTemp = timespanTemp % 86400;
		return timespanTemp * _secondsInOneTick + duration;
	}
	else
	{
		int duration = 0;
		for (int i = 0; i < _tabDuration.size(); ++i)
		{
			int timeSpan = _tabDuration[i].numberOfTicks.count();
			duration += timeSpan % 86400 * _tabDuration[i].speedModifier;
		}
		return duration;
	}
}

// Return a 1 if the timer can and has stopped, and 0 if the timer hasn't started yet, and can't stop as a consequence.
int Clock::stop()
{
	if (_clockOngoing == true) {
		chrono::steady_clock::time_point endedTime = chrono::steady_clock::now();
		chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(endedTime - _startedTime);
		_totalTime += time_span;
		_clockOngoing = false;
		duration tmp = { time_span , _secondsInOneTick };
		_tabDuration.push_back(tmp);
		return 1;
	}
	else {
		return 0;
	}
}

// Return 1 if the speed was changed successfully, and 0 if failed
int Clock::changeSpeed(double multiplier) {
	if (_clockOngoing == true) {
		return 0;
	}
	else {
		if (multiplier > 0 && multiplier <= 60) {
			_secondsInOneTick = multiplier*60;
			return 1;
		}
		else {
			return 0;
		}
	}
}

// Reset the timer to 0 hours, 0 minutes and 0 seconds. Doesn't reset the speed multiplier though !
void Clock::reset() {
	if (_clockOngoing == true) {
		stop();
	}
	_totalTime = chrono::seconds(0);
	_startedTime = {};
	_tabDuration.clear();
}
