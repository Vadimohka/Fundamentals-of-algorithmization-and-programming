#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class ellipse : public Shape
{
public:
    ellipse();
    float radius1 = 100;
    float radius2 = 70;
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // ELLIPSE_H
