#include "Node.h"
#include "Way.h"
#include <iostream>
using std::cout;

Node::Node(int id, int x, int y) : Point{x,y}, _id{id}, _connectedWays(0)
{
    //ctor
}

Node::~Node()
{
    for (int i = 0; i < _connectedWays.size(); i++)
    {
        _connectedWays[i] = nullptr;
        //delete _connectedWays[i];
    }
}

int Node::getId() const
{
    return _id;
}


vector<Way*>& Node::getConnectedWays()
{
    return _connectedWays;
}

void Node::print() const
{
    /*cout << "node " << _id << " connected ways : ";
    for (int i = 0; i < _connectedWays.size(); i++)
    {
        cout << _connectedWays[i]->getId() << ",";
    }
    cout << "\n";*/
}

