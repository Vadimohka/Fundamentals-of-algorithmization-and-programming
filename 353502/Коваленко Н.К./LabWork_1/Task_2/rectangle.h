#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"shape.h"


class rectangle: public Shape
{
public:
    rectangle();
    float length=100;
    float width=50;
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RECTANGLE_H
