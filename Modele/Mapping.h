#ifndef MAPPING_H
#define MAPPING_H

#include <string>
class Simulation;

class Mapping
{
public:
    Mapping(const std::string& mapFileName, Simulation& simulation);
    bool extractMapForSimulation(Simulation& simulation);


private:
    std::string _mapFileName;
};

#endif // MAP_H