#include "Car.h"

Car::Car(Node* startingNode, const Wave &waveCom, Way *way, int speed) : _position{startingNode->getX(), startingNode->getY()}, 
    _waveCommunication{waveCom}, _way{way}, _speed{speed}, _connectedCars(0), _endOfWay{false}, _startingNode{startingNode}
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

Way* Car::getWay() const
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

void Car::setWay(Way* newWay)
{
    _way = newWay;
}

void Car::setStartingNode(Node* newStartingNode)
{
    _startingNode = newStartingNode;
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
    _position.moveOf(_way->slopeX(_startingNode) * _speed, _way->slopeY(_startingNode) * _speed);

    if (traveledDistanceOnTheWay() > _way->nodesDistance())
    {
        if (_startingNode == _way->getNode1()) setPosition(_way->getNode2()->getX(), _way->getNode2()->getY());
        else setPosition(_way->getNode1()->getX(), _way->getNode1()->getY());

        _endOfWay = true;
    }

    
}

double Car::traveledDistanceOnTheWay() const
{
    return sqrt((_position.getX() - _startingNode->getX()) * (_position.getX() - _startingNode->getX()) +
        (_position.getY() - _startingNode->getY()) * (_position.getY() - _startingNode->getY()));
}

