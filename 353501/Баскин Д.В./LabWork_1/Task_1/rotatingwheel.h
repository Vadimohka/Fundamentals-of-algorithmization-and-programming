#ifndef ROTATINGWHEEL_H
#define ROTATINGWHEEL_H

#include "movingcircle.h"

class RotatingWheel : public MovingCircle
{
public:
    RotatingWheel();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void rotateLeft();
    void rotateRight();
};

#endif // ROTATINGWHEEL_H
