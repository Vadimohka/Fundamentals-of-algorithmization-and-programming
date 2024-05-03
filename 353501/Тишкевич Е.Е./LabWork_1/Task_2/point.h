#ifndef POINT_H
#define POINT_H

#include "shape.h"


class point: public Shape
{
public:
    point();
    int xp=0;
    int yp=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void updX(int);
    void updY(int);
    float area() override;
    float perim() override;
};

#endif // POINT_H
