#ifndef CAR_H
#define CAR_H

#include "Point.h"
#include "Wave.h"
#include "Way.h"

// Il manquait cet include
#include "Node.h"

#include <cmath>

#include <vector>

using std::vector;

class Car
{
    public :
        Car(Node* startNode, Wave* waveCom, Way* way, int speed);

        Point getPosition() const;

        Wave* getWaveCommunication() const;

        Way* getWay() const;

        double getSpeed() const;

        bool endOfWay() const;

        vector<Car*>& getConnectedCars();

        void setPosition(int x, int y);

        void setEndOfWay(bool endOfWay);

        void setWay(Way* newWay);

        void setStartingNode(Node* newStartingNode);

        void setSpeed(double newSpeed);

        void moveTo(const Point &newPosition);

        bool communicating(const Car* OtherCar);

        void addCarCommunicating(Car* OtherCar);

        void deleteCarCommunicating();

        void moveOnTheWay();

        void changeRoute(Node* endingNode, Way* finishedWay);

        double traveledDistanceOnTheWay() const; // from the starting node

    private :
        Point _position;
        Wave* _waveCommunication;
        Way* _way;
        int _speed;
        vector<Car*> _connectedCars;
        bool _endOfWay;
        Node* _startingNode;
};

#endif
