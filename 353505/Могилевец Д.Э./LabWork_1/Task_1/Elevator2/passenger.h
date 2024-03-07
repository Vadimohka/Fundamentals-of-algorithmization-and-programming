#ifndef PASSENGER_H
#define PASSENGER_H

#include "movingrectangle.h"

class Passenger : public MovingRectangle
{
public:
    Passenger();
    ~Passenger();
    Passenger(QPointF, qreal, qreal, QColor);
    void comeOnFloor();
    void comeOutFloor();
    void goInElevator();
    void goOutElevator();
    void draw(QPainter&);
    void goToFloor(int);
    bool checkIsInsideElevator();
    int getCurrFloor();
    bool IsOnFloor();
private:
    MovingRectangle* head;
    QPointF onoutFloorShift;
    qreal onoutFloorTime;
    QPointF inoutElevatorShift;
    qreal inoutElevatorTime;
    QPointF ShiftBetweenFloors;
    qreal BetweenFloorsTime;
    bool isInsideElevator;
    bool isOnFloor;
    int currFloor;
    QColor shirtColor;
    QTimer* openclosedoorsdelay;
};

#endif // PASSENGER_H
