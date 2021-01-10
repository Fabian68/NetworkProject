#include "Way.h"

Way::Way(int id, Node* node1, Node* node2) : _id{ id }, _node1 { node1 }, _node2{ node2 }
{
	// Add the current way to the nodes
	_node1->getConnectedWays().push_back(this);
	_node2->getConnectedWays().push_back(this);
}

Way::~Way()
{
	if(_node1) delete _node1;
	if(_node2) delete _node2;
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

int Way::slopeX() const
{
	return _node2->getX() - _node1->getX();
}

int Way::slopeY() const
{
	return _node2->getY() - _node1->getY();
}

double Way::slopeCoefficient() const
{
	return slopeY() / slopeX();
}