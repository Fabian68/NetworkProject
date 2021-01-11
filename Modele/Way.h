#ifndef WAY_H
#define WAY_H

#include "Node.h"

class Way
{
public :
	Way(int id, Node* node1, Node* node2);
	~Way();
	int getId() const;
	Node* getNode1();
	Node* getNode2();
	int slopeX(Node* startingNode) const;
	int slopeY(Node* startingNode) const;
	//double slopeCoefficient() const;
	double nodesDistance() const;

private :
	int _id;
	Node* _node1;
	Node* _node2;
};

#endif