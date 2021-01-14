#include "Car.h"
#include <cstdlib>
#include<vector>

Car::Car(Node* startingNode, Wave* waveCom, Way *way, double speed) : _position{startingNode->getX(), startingNode->getY()},
    _waveCommunication{waveCom}, _way{way}, _speed{speed}, _connectedCars(0), _endOfWay{false}, _startingNode{startingNode}
{
    _connectedCars.reserve(100);
}

Car::~Car()
{
    delete _waveCommunication;
    _startingNode = nullptr;
    _way = nullptr;
    for (int i = 0; i < _connectedCars.size(); i++) _connectedCars[i] = nullptr;
}

Point Car::getPosition() const
{
    return _position;
}

Wave* Car::getWaveCommunication() const
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

// Fonction permetant de montrer si 2 voitures peuvent communiquer.
// "il faut et il suffit de montrer que la distance AB soit inférieur  à la somme de leurs deux rayons"
// Source : "https://fr.answers.yahoo.com/question/index?qid=20130409130107AAIDHhs&guccounter=1&guce_referrer=aHR0cHM6Ly93d3cuZ29vZ2xlLmNvbS8&guce_referrer_sig=AQAAANifShU7Imhh7xNuh7ZgUfYFhy2_2COYq-ELZmh9Oo_lFrZttSQqs1A4BPUjzBKUpswmcw7Tj_ZS3tDcgYgihLMhQQLwPkOk3BxDJ0xP3KJyGCB806YrkSx-T5cdnu9yUjUdVyQII-6o-wNvwamHoqfNv13iuUVcQ4xDwHphUK8a"
bool Car::communicating(const Car* OtherCar)
{
    // (x2 - x1)²
    // x2 est le x de la OtherCar
    // x1 est le x de la car "this"
    double distanceX = pow(OtherCar->getPosition().getX() - this->getPosition().getX(), 2);

    // (y2 - y1)²
    // y2 est le y de la OtherCar
    // y1 est le y de la car "this"
    double distanceY = pow(OtherCar->getPosition().getY() - this->getPosition().getY(), 2);

    // d(A,B)=√(x2 − x1)² + (y2 − y1)²
    double distancePoints = sqrt(distanceX + distanceY);

    // Somme des rayons

        // Rayon de OtherCar
        double r_other = OtherCar->getWaveCommunication()->getRayon();

        // Rayon de this
        double r_this = this->getWaveCommunication()->getRayon();

    double SommeRayons = r_other + r_this;

    if(distancePoints <= SommeRayons) // <= pour sire si les deux voitures sont à la même position
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Car::addCarCommunicating(Car* OtherCar)
{
    if(communicating(OtherCar))
    {
        _connectedCars.push_back(OtherCar);
    }
}

void Car::deleteCarCommunicating()
{
    if(!_connectedCars.empty())
    {
        for(int i = 0 ; i < _connectedCars.size() ; i++)
        {
            if(!communicating(_connectedCars[i]))
            {
                _connectedCars.erase( _connectedCars.begin() + i);
            }
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
            iWay = rand() % endingNode->getConnectedWays().size();
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

