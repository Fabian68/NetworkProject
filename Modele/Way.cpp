#include "Way.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

Way::Way(int id, Node* node1, Node* node2) : _id{ id }, _node1 { node1 }, _node2{ node2 }
{
	// Add the current way to the nodes
	_node1->getConnectedWays().push_back(this);
	_node2->getConnectedWays().push_back(this);
}

Way::~Way()
{
	_node1 = nullptr;
	_node2 = nullptr;
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

int Way::slopeX(Node* startingNode) const
{
	// THE startingNode HAS TO BE THE NODE 1 OR 2 OF THE WAY
	if (startingNode == _node1) return _node2->getX() - _node1->getX();
	else if (startingNode == _node2) return _node1->getX() - _node2->getX();
	else return 0;
}

int Way::slopeY(Node* startingNode) const
{
	if (startingNode == _node1) return _node2->getY() - _node1->getY();
	else if (startingNode == _node2) return _node1->getY() - _node2->getY();
	else return 0;
}

double Way::nodesDistance() const
{
	return sqrt((_node1->getX()-_node2->getX()) * (_node1->getX()-_node2->getX()) +
				(_node1->getY()-_node2->getY()) * (_node1->getY()-_node2->getY()));
}

void Way::print() const
{
	//cout << "way " << _id << " : node1 " << _node1->getId() << ", node2 " << _node2->getId() << endl;
}

/*
double Way::slopeCoefficient() const
{
	return slopeY() / slopeX();
}*/
