#ifndef MAP_H
#define MAP_H

#include <string>
class Simulation;

class Map
{
public:
    Map(const string& mapFileName, Simulation& simulation);
    virtual ~Map();
    void extractMapForSimulation(Simulation& simulation);


private:
    string _mapFileName;
};

#endif // NODE_H
