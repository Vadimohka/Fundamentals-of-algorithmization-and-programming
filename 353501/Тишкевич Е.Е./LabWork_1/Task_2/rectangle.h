#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"shape.h"


class Rectangle: public Shape
{
public:
    Rectangle();
    float len=250;
    float wid=150;

     float perim() override;
    float area() override;
    float getWid()override;
    float getHei()override;

     void setWid(float)override;
    void setHei(float)override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RECTANGLE_H
