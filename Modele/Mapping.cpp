#include "Mapping.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Simulation.h"

using std::string;


Mapping::Mapping(const string& mapFileName, Simulation& simulation) : _mapFileName{mapFileName}
{
	extractMapForSimulation(simulation);
}


bool Mapping::extractMapForSimulation(Simulation& simulation)
{
	std::ifstream mapFile{ _mapFileName };
	if (!mapFile.is_open()) return false;

	char indic;
	mapFile >> indic;
	if (indic == 'n')
	{
		int nbNodes;
		mapFile >> nbNodes;
		for (int i = 0; i < nbNodes; i++)
		{
			int id, x, y;
			mapFile >> id >> x >> y;
			simulation._nodes.push_back(new Node(id, x, y));
		}
	}

	mapFile >> indic;
	if (indic == 'w')
	{
		int nbWays;
		mapFile >> nbWays;
		for (int i = 0; i < nbWays; i++)
		{
			int id, idNode1, idNode2;
			mapFile >> id >> idNode1 >> idNode2;
			simulation._ways.push_back( new Way(id, simulation._nodes[idNode1], simulation._nodes[idNode2]) );
		}
	}

	return true;
}
