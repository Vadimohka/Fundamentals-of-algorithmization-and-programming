#ifndef HEXAGON_H
#define HEXAGON_H

#include"basicshape.h"

class Hexagon: public BasicShape
{
public:
    Hexagon();
    float area() override;
    float perimeter() override;
    void setRadius(int value) override;
    float getRadius() override;
private:
    int radius = 100;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // HEXAGON_H
