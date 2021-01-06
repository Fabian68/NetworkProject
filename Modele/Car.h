#ifndef CAR_H
#define CAR_H

#include "Point.h"
#include "Wave.h"
#include "Way.h"

#include <vector>

using namespace std;

class Car
{
    public :
        Car(const Point &CarPosition, const Wave &WaveCom, const Way &way, double speed);

        Point CarPosition() const;

        Wave CarWaveComunication() const;

        Way CarOnWay() const;

        double Speed() const;

        vector<Car> CarCommunicate() const;

        void CarMovingOn(const Point &MovePoint);

        void AddCarCommunicating(const Car &OtherCar);

        void DeleteCarCommunicating();

        void SetCarWay(const Way &OtherWay);

        void SetSpeed(double NewSpeed);

    private :
        Point _PositionOfCar;
        Wave _WaveComunication;
        Way _Way;
        double _Speed;
        vector<Car> _CommunicationVToV;
};

#endif
