#include "Node.h"
#include "Way.h"

Node::Node(int id, int x, int y) : Point{x,y}, _id{id}, _connectedWays(0)
{
    //ctor
}

Node::~Node()
{
    for (int i = 0; i < _connectedWays.size(); i++)
    {
        delete _connectedWays[i];
    }
}

int Node::getId() const
{
    return _id;
}


vector<Way*> Node::getConnectedWays()
{
    return _connectedWays;
}

