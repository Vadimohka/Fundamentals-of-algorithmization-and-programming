#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"


class rectangle: public Shape
{
public:
    rectangle();
    float length=150;
    float width=100;
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RECTANGLE_H
