#ifndef CAR_H
#define CAR_H

#include "Point.h"

class Car
{
    public :
        Car(const Point &CarPosition);

        Point CarPosition() const;

        void CarMovingOn(const Point &MovePoint);

        void CarComunicating(const Car &OtherCar);

    private :
        Point _PositionOfCar;

};

#endif
