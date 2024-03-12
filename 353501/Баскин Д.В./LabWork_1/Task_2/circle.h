#ifndef CIRCLE_H
#define CIRCLE_H

#include "basicshape.h"

class Circle : public BasicShape
{
public:
    Circle();
    float area() override;
    float perimeter() override;
    void setRadius(int value) override;
    float getRadius() override;
private:
    int radius = 100;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // CIRCLE_H
