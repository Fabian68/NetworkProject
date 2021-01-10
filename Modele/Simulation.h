#ifndef SIMULATION_H
#define SIMULATION_H
#include "Mesh.h"
#include "Car.h"
#include "Way.h"
#include "Node.h"
#include "Mapping.h"

using std::vector;

class Simulation
{
	
public :
	Simulation();
	~ Simulation();
	//Car operator[](int i)const;
	int getNumberOfCars()const;
	Mesh getMesh();
	vector<Car*>& getCars();
	vector<Node*>& getNodes();
	vector<Way*>& getWays();


	//Way operator[](int i)const; non possible classe vide
private :
	vector<Car*> _cars;
	vector<Node*> _nodes;
	vector<Way*> _ways;

	Mesh _mesh;
	int _meshRadius;
	int _colSizeMesh;
	int _lineSizeMesh;

	Mapping* _mapping;
};


#endif