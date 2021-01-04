#include "Car.h"

Car::Car(const Point &CarPosition, const Wave &WaveCom) : _PositionOfCar{CarPosition}, _WaveComunication{WaveCom}
{}

Point Car::CarPosition() const
{
    return _PositionOfCar;
}

Wave Car::CarWaveComunication() const
{
    return _WaveComunication;
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
