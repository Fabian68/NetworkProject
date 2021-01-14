#include "Simulation.h"
#include <ctime>
#include <string>
#include <QDebug>
#include <QDir>
#include <cstdlib>

Simulation::Simulation() : _cars(0), _nodes(0), _ways(0), speedSimulation(0.1)
{
	srand(time(NULL));

	_cars.reserve(100);
	_nodes.reserve(100);
	_ways.reserve(100);
	Point Origine = Point(5.0, 5.0);
	_meshRadius = 50;
	_colSizeMesh = 400;
	_lineSizeMesh = 400;

	// 300x300 Hexagones de 50 metres de circonference
	_mesh = Mesh(Origine, _meshRadius, _lineSizeMesh, _colSizeMesh);

	// fill Nodes and Ways
    qDebug()<<"Path de base : "<<QDir::currentPath();
    // LE PATH DE BASE EST DEHORS DU PROJET ! IL FAUT EN SORTIR ET ALLER DANS LE DOSSIER DU PROJET POUR LIRE LE FICHIER
    _mapping = new Mapping("../NetworkProject/map.txt", *this);

    // create an unique car
    addCar();
}
Simulation::~Simulation()
{
	for (int i = 0; i < _nodes.size(); i++) delete _nodes[i];

	for (int i = 0; i < _ways.size(); i++) delete _ways[i];

	for (int i = 0; i < _cars.size(); i++) delete _cars[i];

	delete _mapping;
}


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

Node* Simulation::randomNode()
{
    int iNode= rand() % _nodes.size();
    return _nodes[iNode];
}

void Simulation::addCar()
{
    Node* node= randomNode();
    _cars.push_back(new Car(node, new Wave(), node->getConnectedWays()[0], speedSimulation));
}

void Simulation::removeACar()
{
    if(_cars.size()>0)
    {
        delete _cars[_cars.size()-1];
        _cars.pop_back();
    }
}

void Simulation::update()
{
	// move each car
	for (int i = 0; i < _cars.size(); i++)
	{
		// if the car still exists move it
		if (_cars[i]) _cars[i]->moveOnTheWay();
	}

    // SUITE BUGUEE, CRASH

	double R;
	double G;
	double B;

	int nCarsInOneHexagon;

	for (int i = 0;i < _mesh.getColSize();i++) {
		for (int j = 0;j < _lineSizeMesh;j++) {
			_mesh[i][j].setColor({ 1.0,1.0,1.0,1.0 });
            _mesh[i][j].settransparance(0.0);
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

void Simulation::print() const
{
	/*for (int i = 0; i < _nodes.size(); i++) _nodes[i]->print();
	cout << endl;
	for (int i = 0; i < _ways.size(); i++) _ways[i]->print();
	cout << "sizes nodes " << _nodes.size() << " ways " << _ways.size();
	*/
}
