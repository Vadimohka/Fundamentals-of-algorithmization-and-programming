#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle();
    int a = 0;
    int b = 0;
    float findArea() override;
    float findPerimeter() override;
    void setAB(int, int);
    int getA();
    int getB();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RECTANGLE_H
