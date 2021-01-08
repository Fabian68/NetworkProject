#include "Node.h"
#include "Way.h"

Node::Node(int id, int x, int y) : Point{x,y}, _id{id}, _connectedWays(0)
{
    //ctor
}

Node::~Node()
{
    //dtor
}

int Node::getId() const
{
    return _id;
}

vector<Way*> Node::getConnectedWays()
{
    return _connectedWays;
}

