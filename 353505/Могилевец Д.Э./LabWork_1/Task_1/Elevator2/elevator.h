#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "movingrectangle.h"

class Elevator : public MovingRectangle
{
public:
    explicit Elevator(QWidget *parent = nullptr);
    ~Elevator();
    Elevator(const QPointF&, const QSizeF&);
    void drawCorp(QPainter&);
    void drawDoors(QPainter&);
    void openDoors();
    void closeDoors();
    void goToFloor(int);
    int getCurrFloor();
    bool checkDoors();
private:
    void setSize(const QPointF&, const QSizeF&);
    void setSettings(qreal, qreal, const QPointF&,int, bool);
    MovingRectangle* LeftDoor;
    MovingRectangle* RightDoor;
    MovingRectangle* LeftWall;
    MovingRectangle* RightWall;
    int CurrFloor;
    QPointF ShiftBetweenFloors;
    qreal BetweenFloorsTime;
    qreal DoorOpenCloseTime;
    QPointF DoorsShift;
    bool DoorsAreOpened;
    QTimer* openclosedoordelay;
};


#endif // ELEVATOR_H
