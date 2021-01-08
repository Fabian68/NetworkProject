#include "Map.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Simulation.h"

using namespace std;


Map::Map(const string& mapFileName, Simulation& simulation) : _mapFileName{mapFileName}
{
	extractMapForSimulation(simulation);
}

Map::~Map()
{
}

void Map::extractMapForSimulation(Simulation& simulation)
{
	ifstream mapFile(_mapFileName);
	if () return;
}
