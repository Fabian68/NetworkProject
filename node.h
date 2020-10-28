#ifndef NODE_H
#define NODE_H

#include "point.h

class Node : public Point
{
    public:
        Node(int id, int x, int y);
        virtual ~Node();
        int getId() const;

    protected:

    private:
        int _id;
};

#endif // NODE_H
