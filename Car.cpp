#include "Car.h"

Car::Car(const Point &CarPosition) : _PositionOfCar{CarPosition}
{}

Point Car::CarPosition() const
{
    return _PositionOfCar;
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
