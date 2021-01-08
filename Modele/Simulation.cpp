#include "Simulation.h"

Simulation::Simulation()
{
	_cars.reserve(100);
	_ways.reserve(100);
	_nodes.reserve(100);
	Point Origine = Point(5.0, 5.0);
	_meshRadius = 50;
	_colSizeMesh = 300;
	_lineSizeMesh = 300;
	// 300x300 Hexagones de 50 metres de circonférence
	_mesh = Mesh(Origine, _meshRadius, _lineSizeMesh, _colSizeMesh);
	_mapping = new Mapping("map.txt", *this);
}

Car Simulation::operator[](int i) const
{
	return _cars[i];
}

int Simulation::getNumberOfCars() const
{
	return _cars.size();
}

Mesh Simulation::getMesh()
{
	return _mesh;
}

std::vector<Way*> Simulation::getWays()
{
	return _ways;
}

std::vector<Node*> Simulation::getNodes()
{
	return _nodes;
}
