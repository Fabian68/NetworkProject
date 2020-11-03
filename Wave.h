#ifndef WAVE_H
#define WAVE_H


class Wave
{
public:
	/*
	* As soon as defaults value can be found, remove the empty constructor
	* and add defaults value to the second constructor
	*/
	Wave();
	Wave(double rayon, double strength, double frequency);
	void setRayon(double rayon);
	void setStrength(double strength);
	void setFrequency(double frequency);
	double getRayon();
	double getStrength();
	double getFrequency();

	//Functions used for the Free space propagation model
	double getDensityOfStrength(double distanceFromTransmettor);
	double getAvailableStrength(double distanceFromTransmettor);
	
	//The following function should propably be on the receiver, not the sender
	double getSignalAttenuation(double emettorStrength, double receivedStrength);

private:
	// Base values decided in the Class diagram
	double _rayon;
	double _strength;
	double _frequency;

	//Value for the Free space propagation model
	double _antennaGain;
	double _antennaEffectiveArea;
};

#endif
