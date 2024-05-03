#ifndef HEXAGON_H
#define HEXAGON_H

#include"shape.h"


class Hexagon: public Shape
{
public:
    Hexagon();
    float radius=70;
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // HEXAGON_H
