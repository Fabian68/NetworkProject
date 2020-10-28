#include "node.h"

Node::Node(int id, int x, int y) : Point{x,y}, _id{id}
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

