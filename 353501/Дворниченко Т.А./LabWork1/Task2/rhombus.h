#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "shape.h"

class Rhombus: public Shape
{
public:
    float size = 45;
    Rhombus();
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RHOMBUS_H
