#ifndef WHEEL_H
#define WHEEL_H

#include <QtWidgets>

#include "circle.h"

class Wheel : public Circle
{
public:
    Wheel();
    QGraphicsEllipseItem *wheel;
    QGraphicsLineItem *line;
    int rotationAngle;
    void  rotateRight();
    void  rotateLeft();
};

#endif // WHEEL_H

