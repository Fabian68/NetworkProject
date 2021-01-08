#ifndef SIMULATION_H
#define SIMULATION_H
#include "Mesh.h"
#include "Car.h"
#include "Way.h"
#include "Node.h"
#include "Mapping.h"

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
	std::vector<Way*> _ways;
	std::vector<Node*> _nodes;
	Mesh _mesh;
	int _meshRadius;
	int _colSizeMesh;
	int _lineSizeMesh;

	Mapping* _mapping;
	friend class Mapping;
};


#endif