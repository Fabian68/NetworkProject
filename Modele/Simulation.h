#ifndef SIMULATION_H
#define SIMULATION_H
#include "Mesh.h"
#include "Car.h"
#include "Way.h"

class Simulation
{
public :
	Simulation();
	Car operator[](int i)const;
	int getNumberOfCars()const;
	Mesh getMesh();
	//Way operator[](int i)const; non possible classe vide
private :
	std::vector<Car> _cars;
	std::vector<Way> _ways;
	Mesh _mesh;
	int _meshRadius;
	int _colSizeMesh;
	int _lineSizeMesh;
};


#endif