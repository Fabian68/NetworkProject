#include "Simulation.h"

Simulation::Simulation() : _cars(0), _nodes(0), _ways(0)
{
	srand(time(NULL));

	_cars.reserve(100);
	_nodes.reserve(100);
	_ways.reserve(100);
	Point Origine = Point(5.0, 5.0);
	_meshRadius = 50;
	_colSizeMesh = 300;
	_lineSizeMesh = 300;
	// 300x300 Hexagones de 50 metres de circonférence
	_mesh = Mesh(Origine, _meshRadius, _lineSizeMesh, _colSizeMesh);
	// fill Nodes and Ways
	_mapping = new Mapping("map.txt", *this);
	// create cars
	// todo
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

void Simulation::addCar(Car* car)
{
	_cars.push_back(car);
}

void Simulation::update()
{
	// move each car
	for (int i = 0; i < _cars.size(); i++)
	{
		// if the car still exists
		if (_cars[i])
		{
			// move it if it is not on the end of the way
			if(!_cars[i]->endOfWay()) _cars[i]->moveOnTheWay();

			// otherwise change its way
			else
			{
				// choose a random Way which is starting from the ending Node
				//	A METTRE DANS CAR
			}
		}
	}

	//todo connections
}

