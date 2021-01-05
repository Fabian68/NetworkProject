#ifndef WAY_H
#define WAY_H

#include "Node.h"

class Way
{
public :
	Way();
	vector<Node*> getNodes();

private :
	vector<Node*> _nodes;
};

#endif