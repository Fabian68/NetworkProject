#include "Car.h"

Car::Car(const Point &carPosition, const Wave &waveCom, const Way &way, int speed) : _position{carPosition}, _waveCommunication{waveCom},
        _way{way}, _speed{speed}, _connectedCars(0), _endOfWay{false}
{
    _connectedCars.reserve(100);
}

Point Car::getPosition() const
{
    return _position;
}

Wave Car::getWaveCommunication() const
{
    return _waveCommunication;
}

Way Car::getWay() const
{
    return _way;
}

double Car::getSpeed() const
{
    return _speed;
}

bool Car::endOfWay() const
{
    return _endOfWay;
}

vector<Car*>& Car::getConnectedCars()
{
    return _connectedCars;
}

void Car::setPosition(int x, int y)
{
    _position.moveTo(x, y);
}

void Car::setEndOfWay(bool endOfWay)
{
    _endOfWay = endOfWay;
}

void Car::setWay(const Way& newWay)
{
    _way = newWay;
    //setPosition(?) ?
}

void Car::setSpeed(double newSpeed)
{
    _speed = newSpeed;
}


void Car::moveTo(const Point &newPosition)
{
    Point oldPosition = _position;
    _position = newPosition;
}

bool Car::communicating(const Car &OtherCar)
{
    // La voiture peut-elle communiquer avec l'autre ?
    return true;
}

void Car::addCarCommunicating(const Car &OtherCar)
{
    if(communicating(OtherCar))
    {
        // Ajout dans le vecteur
    }
}

void Car::deleteCarCommunicating()
{
    if(!_connectedCars.empty())
    {
        for(int i = 0 ; i < _connectedCars.size() ; i++)
        {
            // Test si la voiture en [i] peut communiquer
        }
    }
}

void Car::moveOnTheWay(bool node1ToNode2)
{
    Node* destination;
    if (node1ToNode2)
    {
        destination = _way.getNode2();
        _position.moveOf(_way.slopeX() * _speed, _way.slopeY() * _speed);
    }

    else
    {
        destination = _way.getNode1();
        _position.moveOf(-_way.slopeX() * _speed, -_way.slopeY() * _speed);
    }

    // if dépassé le remettre sur le node
    
}

