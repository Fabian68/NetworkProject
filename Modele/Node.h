#ifndef NODE_H
#define NODE_H

#include "Point.h"
#include <vector>

using std::vector;
class Way;

class Node : public Point
{
    public:
        Node(int id, int x, int y);
        virtual ~Node();
        int getId() const;
        vector<Way*>& getConnectedWays();
        void print() const;

    private:
        int _id;
        vector<Way*> _connectedWays;

};

#endif // NODE_H
