#include "Wave.h"

Wave::Wave()
{}

Wave::Wave(double rayon, double strength, double frequency) : _rayon{ rayon }, _strength { strength }, _frequency{ frequency }
{}

void Wave::setRayon(double rayon)
{
	_rayon = rayon;
}

void Wave::setStrength(double strength)
{
	_strength = strength;
}

void Wave::setFrequency(double frequency)
{
	_frequency = frequency;
}

double Wave::getRayon()
{
	return _rayon;
}

double Wave::getStrength()
{
	return _strength;
}

double Wave::getFrequency()
{
	return _frequency;
}