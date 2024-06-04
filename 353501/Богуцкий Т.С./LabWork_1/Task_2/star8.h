#ifndef STAREIGHT_H
#define STAREIGHT_H

#include "shape.h"

class Star8: public Shape
{
public:
    Star8();
    float area() override;
    float perimeter() override;

private:
    float radius1=80;
    float radius2=100;
    int count=8;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // STAREIGHT_H
