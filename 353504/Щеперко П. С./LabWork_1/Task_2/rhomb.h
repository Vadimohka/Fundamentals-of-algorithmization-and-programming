#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"

class Rhomb : public Figure
{
public:
    Rhomb();
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

#endif // RHOMB_H
