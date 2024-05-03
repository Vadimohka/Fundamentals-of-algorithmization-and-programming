#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid : public Figure
{
public:
    Trapezoid();
    int a = 0;
    int b = 0;
    int h = 0;
    float findArea() override;
    float findPerimeter() override;
    void setABH(int, int, int);
    int getA();
    int getB();
    int getH();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // TRAPEZOID_H
