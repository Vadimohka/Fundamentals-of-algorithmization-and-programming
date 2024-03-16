#ifndef ROMB_H
#define ROMB_H

#include "shape.h"

class Romb: public Shape
{
public:
    Romb();
    float len = 75;
    double widS=1.00;
    double heiS=1.00;
    float perim() override;
    float area() override;
    float getDiam1()override;
    float getDiam2()override;
    void setDiam1(float)override;
    void setDiam2(float)override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // ROMB_H
