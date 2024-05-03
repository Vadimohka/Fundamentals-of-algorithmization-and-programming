#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure
{
public:
    Hexagon();
    int r = 0;
    float findArea() override;
    float findPerimeter() override;
    void setR(int);
    int getR();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // HEXAGON_H
