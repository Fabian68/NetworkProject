#include "Wave.h"

const double PI = 3.14159265359;

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

//////////////////////////////////
// Free space propagation model //
//////////////////////////////////

double Wave::getDensityOfStrength(double distanceFromTransmettor)
{
	return (_strength * _antennaGain) / (4 * PI * (distanceFromTransmettor * distanceFromTransmettor));
}

double Wave::getAvailableStrength(double distanceFromTransmettor)
{
	return ((_strength * _antennaGain) / (4 * PI * (distanceFromTransmettor * distanceFromTransmettor))) * _antennaEffectiveArea;
}

double Wave::getSignalAttenuation(double emettorStrength, double receivedStrength)
{
	return emettorStrength / receivedStrength;
}