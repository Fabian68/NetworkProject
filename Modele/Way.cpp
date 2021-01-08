#include "Way.h"

Way::Way(int id, Node* node1, Node* node2) : _id{ id }, _node1 { node1 }, _node2{ node2 }
{
	// Add the current way to the nodes
	_node1->getConnectedWays().push_back(this);
	_node2->getConnectedWays().push_back(this);
}

Way::~Way()
{
	//todo
}

int Way::getId() const
{
	return _id;
}

Node* Way::getNode1()
{
	return _node1;
}

Node* Way::getNode2()
{
	return _node2;
}

