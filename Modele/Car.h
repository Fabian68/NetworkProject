#ifndef CAR_H
#define CAR_H

#include "Point.h"
#include "Wave.h"
#include "Way.h"

#include <vector>

using std::vector;

class Car
{
    public :
        Car(const Point &carPosition, const Wave &waveCom, const Way &way, int speed);

        Point getPosition() const;

        Wave getWaveCommunication() const;

        Way getWay() const;

        double getSpeed() const;

        bool endOfWay() const;

        vector<Car*>& getConnectedCars();

        void setPosition(int x, int y);

        void setEndOfWay(bool endOfWay);

        void setWay(const Way& newWay);

        void setSpeed(double newSpeed);

        void moveTo(const Point &newPosition);

        bool communicating(const Car &OtherCar);

        void addCarCommunicating(const Car &OtherCar);

        void deleteCarCommunicating();

        void moveOnTheWay(bool node1ToNode2);

    private :
        Point _position;
        Wave _waveCommunication;
        Way _way;
        int _speed;
        vector<Car*> _connectedCars;
        bool _endOfWay;
};

#endif
