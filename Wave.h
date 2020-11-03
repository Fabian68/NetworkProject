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
	double getDensityOfStrength(double antennaGain, double distanceFromTransmettor);
	double getAvailableStrength(double antennaGain, double distanceFromTransmettor, double antennaEffectiveArea);
	
	//The following function should propably be on the receiver, not the sender
	double getSignalAttenuation(double emettorStrength, double receivedStrength);

private:
	// Base values decided in the Class diagram
	double _rayon;
	double _strength;
	double _frequency;

	/*
	* No value for the Free space propagation model, as it use values from the transmettor and
	* the receptor
	*/
};

#endif
