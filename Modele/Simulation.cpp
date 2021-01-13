#include "Simulation.h"
#include <ctime>

Simulation::Simulation() : _cars(0), _nodes(0), _ways(0)
{
	srand(time(NULL));

	_cars.reserve(100);
	_nodes.reserve(100);
	_ways.reserve(100);
	Point Origine = Point(5.0, 5.0);
	_meshRadius = 50;
	_colSizeMesh = 400;
	_lineSizeMesh = 400;
	// 300x300 Hexagones de 50 metres de circonférence
	_mesh = Mesh(Origine, _meshRadius, _lineSizeMesh, _colSizeMesh);
	// fill Nodes and Ways
	_mapping = new Mapping("map.txt", *this);
	// create a car without wave
	_cars.push_back(new Car(_nodes[0], nullptr, _nodes[0]->getConnectedWays()[0], 1));
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
		// if the car still exists move it
		if (_cars[i]) _cars[i]->moveOnTheWay();
	}
	double R;
	double G;
	double B;

	int nCarsInOneHexagon;

	for (int i = 0;i < _mesh.getColSize();i++) {
		for (int j = 0;j < _lineSizeMesh;j++) {
			_mesh[i][j].setColor({ 1.0,1.0,1.0,1.0 });
			_mesh[i][j].settransparance(1.0);
			nCarsInOneHexagon = 0;
			R = 0;G = 0;B = 0;
			for (int i = 0; i < _cars.size(); i++)
			{
				
				if (_cars[i]) {
					if (_mesh[i][j].contains(_cars[i]->getPosition())) {
						nCarsInOneHexagon++;
						R += (double)(_cars[i]->getWaveCommunication()->getFrequency());
						G += (double)(_cars[i]->getWaveCommunication()->getRayon());
						B += (double)(_cars[i]->getWaveCommunication()->getStrength());
					}
				}
			}
			if (nCarsInOneHexagon > 0) {
				//calcul rgb et transparance
				R = (R / 255.0)  ;
			}
		}
	}

	//todo connections
}

