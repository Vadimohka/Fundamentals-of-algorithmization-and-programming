#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"shape.h"

class Triangle: public Shape
{
public:
    Triangle();
    float size=60;
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // TRIANGLE_H
