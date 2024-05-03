#ifndef STAREIGHT_H
#define STAREIGHT_H

#include "shape.h"

class Stareight: public Shape
{
public:
    Stareight();
    float area() override;
    float perimeter() override;
private:
    float radius1=100;
    float radius2=100;
    int count=8;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // STAREIGHT_H
