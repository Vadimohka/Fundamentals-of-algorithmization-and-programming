#include "movingcircle.h"
#ifndef ROTATABLECIRCLE_H
#define ROTATABLECIRCLE_H



class RotatableCircle : public MovingCircle{
public:
    int angle=0;
    QGraphicsEllipseItem *circle;
    QGraphicsLineItem *radius;
    RotatableCircle();
    void rotate();
};


#endif // ROTATABLECIRCLE_H
