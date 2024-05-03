#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"


class Rectangle : public Figure
{

public:

    Rectangle();
    float Area() override;
    float Perimeter() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RECTANGLE_H
