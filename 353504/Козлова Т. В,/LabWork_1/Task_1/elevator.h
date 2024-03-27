#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "rectangle.h"

class Elevator : public Rectangle
{
public:
    Elevator(int x, int y, int width, int height, QWidget* parent = nullptr);
    ~Elevator();

    void openDoors();
    void stopMovingDoors();

    bool isDoorsActive();
    bool isMoving();

private:
    void paintEvent(QPaintEvent* event);

    void openingDoors();
    void closingDoors();

    int leftdoorX = x + 10;
    int leftdoorWidth = width / 2 - 11;
    int doorHeight = height - 10;
    int rightdoorX = leftdoorX + leftdoorWidth + 2;
    int rightdoorWidth = leftdoorWidth;

    QTimer* openDoorsTimer;
    QTimer* closeDoorsTimer;
};


#endif // ELEVATOR_H
