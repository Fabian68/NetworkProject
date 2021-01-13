#include "Simulation.h"

Simulation::Simulation() : _cars(0), _nodes(0), _ways(0)
{
	_cars.reserve(100);
	_nodes.reserve(100);
	_ways.reserve(100);
	Point Origine = Point(5.0, 5.0);
	_meshRadius = 50;
	_colSizeMesh = 400;
	_lineSizeMesh = 400;
	// 300x300 Hexagones de 50 metres de circonférence
	_mesh = Mesh(Origine, _meshRadius, _lineSizeMesh, _colSizeMesh);
	_mapping = new Mapping("map.txt", *this);
}
Simulation::~Simulation()
{
	// call the Way destructor for each connected way in the node
	for (int i = 0; i < _nodes.size(); i++)
	{
		if (_nodes[i]) delete _nodes[i];
	}

	//todos car etc
}
/*
Car Simulation::operator[](int i) const
{
	return *_cars[i];
}*/

int Simulation::getNumberOfCars() const
{
	return _cars.size();
}

Mesh Simulation::getMesh()
{
	return _mesh;
}

vector<Car*>& Simulation::getCars()
{
	return _cars;
}

vector<Node*>& Simulation::getNodes()
{
	return _nodes;
}

vector<Way*>& Simulation::getWays()
{
	return _ways;
}

void Simulation::addCar(Car* C)
{
	_cars.push_back(C);
}

void Simulation::update()
{
//todo
}

