#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle: public Shape
{
public:
    Circle();
    float area() override;
    float perim() override;

     float getRadF()override;
     float getRadS()override;

    void setRadF(float)override;
     void setRadS(float)override;

    float radA=150;
    float radB=150;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // CIRCLE_H
