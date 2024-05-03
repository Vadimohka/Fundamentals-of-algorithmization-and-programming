#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"figures.h"

class Triangle: public Figures
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
