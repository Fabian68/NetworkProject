#include "Car.h"

Car::Car(const Point &CarPosition, const Wave &WaveCom, const Way &way, double speed) : _PositionOfCar{CarPosition}, _WaveComunication{WaveCom}, _Way{way}, _Speed{speed}
{}

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

void Car::CarMovingOn(const Point &MovePoint)
{
    Point OldPosition = CarPosition();
    _PositionOfCar = MovePoint;
}

void Car::CarComunicating(const Car &OtherCar)
{
    // ???
}

void Car::SetCarWay(const Way &OtherWay)
{
    _Way = OtherWay;
}

void Car::SetSpeed(double NewSpeed)
{
    _Speed = NewSpeed;
}
