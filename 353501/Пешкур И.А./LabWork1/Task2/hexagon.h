#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure
{



public:

    Hexagon();
    float Area() override;
    float Perimeter() override;

protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};

#endif // HEXAGON_H
