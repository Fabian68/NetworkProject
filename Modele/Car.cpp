#include "Car.h"
#include <cstdlib>

Car::Car(Node* startingNode, Wave* waveCom, Way *way, int speed) : _position{startingNode->getX(), startingNode->getY()}, 
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

void Car::moveOnTheWay()
{
    _position.moveOf(_way->slopeX(_startingNode) * _speed, _way->slopeY(_startingNode) * _speed);

    if (traveledDistanceOnTheWay() > _way->nodesDistance())
    {
        Node* endingNode;
        if (_startingNode == _way->getNode1()) endingNode = _way->getNode2();
        else endingNode = _way->getNode1();

        setPosition(endingNode->getX(), endingNode->getY());
        changeRoute(endingNode, _way);
    }

    
}

void Car::changeRoute(Node* endingNode, Way* finishedWay)
{
    if (endingNode->getConnectedWays().size() > 1)
    {
        int iWay;
        do
        {
            int iWay = rand() * endingNode->getConnectedWays().size();
        } while (endingNode->getConnectedWays()[iWay]->getId() == finishedWay->getId());

        setWay(endingNode->getConnectedWays()[iWay]);
    }

    else
    {
        // nothing to do ?
    }

    setStartingNode(endingNode);
    
}

double Car::traveledDistanceOnTheWay() const
{
    return sqrt((_position.getX() - _startingNode->getX()) * (_position.getX() - _startingNode->getX()) +
        (_position.getY() - _startingNode->getY()) * (_position.getY() - _startingNode->getY()));
}

