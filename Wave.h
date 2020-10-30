#ifndef WAVE_H
#define WAVE_H


class Wave
{
public:
	Wave();
	Wave(double rayon, double strength, double frequency);
	void setRayon(double rayon);
	void setStrength(double strength);
	void setFrequency(double frequency);
	double getRayon();
	double getStrength();
	double getFrequency();
private:
	double _rayon;
	double _strength;
	double _frequency;
};

#endif
