#ifndef STARFIVE_H
#define STAFIVE_H

#include "shape.h"

class Starfive: public Shape
{
public:
    Starfive();
    float area() override;
    float perimeter() override;
private:
    float radius1 = 80;
    float radius2 = 80;
    int count = 5;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // Starfive_H
