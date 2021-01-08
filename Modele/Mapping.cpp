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

	// Fill Node and Way vectors with the map file

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
			simulation.getNodes().push_back(new Node(id, x, y));
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
			simulation.getWays().push_back( new Way(id, simulation.getNodes()[idNode1], simulation.getNodes()[idNode2]) );
		}
	}

	return true;
}
