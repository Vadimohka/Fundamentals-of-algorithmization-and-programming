#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "wheel.h"


class Rectangle : public Wheel
{
    Q_OBJECT
    QGraphicsRectItem *helper = nullptr;
    QGraphicsEllipseItem *helper1 = nullptr;
    QGraphicsEllipseItem *helper2 = nullptr;


public:
    Rectangle();
    ~Rectangle();
    void Start();
    void Restart();

};

#endif // RECTANGLE_H

