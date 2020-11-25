#ifndef CAR_H
#define CAR_H

#include "Point.h"
#include "Wave.h"

class Car
{
    public :
        Car(const Point &CarPosition, const Wave &WaveCom);

        Point CarPosition() const;

        Wave CarWaveComunication() const;

        void CarMovingOn(const Point &MovePoint);

        void CarComunicating(const Car &OtherCar);

    private :
        Point _PositionOfCar;
        Wave _WaveComunication;
};

#endif
