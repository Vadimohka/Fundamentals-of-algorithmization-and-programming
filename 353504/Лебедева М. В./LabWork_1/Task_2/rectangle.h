#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"figures.h"


class Rectangle: public Figures
{
public:
    Rectangle();
    float length=100;
    float width=50;
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RECTANGLE_H
