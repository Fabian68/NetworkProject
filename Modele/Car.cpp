#include "Car.h"

Car::Car(const Point &CarPosition, const Wave &WaveCom, const Way &way, double speed) : _PositionOfCar{CarPosition}, _WaveComunication{WaveCom}, _Way{way}, _Speed{speed}
{
    Car::_CommunicationVToV.reserve(100);
}

Point Car::CarPosition() const
{
    return _PositionOfCar;
}

Wave Car::CarWaveComunication() const
{
    return _WaveComunication;
}

Way Car::CarOnWay() const
{
    return _Way;
}

double Car::Speed() const
{
    return _Speed;
}

vector<Car> Car::CarCommunicate() const
{
    return _CommunicationVToV;
}

void Car::CarMovingOn(const Point &MovePoint)
{
    Point OldPosition = CarPosition();
    _PositionOfCar = MovePoint;
}

bool Car::Communicating(const Car &OtherCar)
{
    // La voiture peut-elle communiquer avec l'autre ?
}

void Car::AddCarCommunicating(const Car &OtherCar)
{
    if(Communicating(OtherCar))
    {
        // Ajout dans le vecteur
    }
}

void Car::DeleteCarCommunicating()
{
    if(!_CommunicationVToV.empty())
    {
        for(int i = 0 ; i < _CommunicationVToV.size() ; i++)
        {
            // Test si la voiture en [i] peut communiquer
        }
    }
}

void Car::SetCarWay(const Way &OtherWay)
{
    _Way = OtherWay;
}

void Car::SetSpeed(double NewSpeed)
{
    _Speed = NewSpeed;
}
