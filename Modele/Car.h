#ifndef CAR_H
#define CAR_H

#include "Point.h"
#include "Wave.h"
#include "Way.h"

class Car
{
    public :
        Car(const Point &CarPosition, const Wave &WaveCom, const Way &way, double speed);

        Point CarPosition() const;

        Wave CarWaveComunication() const;

        Way CarOnWay() const;

        double Speed() const;

        void CarMovingOn(const Point &MovePoint);

        void CarComunicating(const Car &OtherCar);

        void SetCarWay(const Way &OtherWay);

        void SetSpeed(double NewSpeed);

    private :
        Point _PositionOfCar;
        Wave _WaveComunication;
        Way _Way;
        double _Speed;
};

#endif
