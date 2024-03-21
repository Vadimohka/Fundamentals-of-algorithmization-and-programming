#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

class Rhombus : public Figure
{
public:
    Rhombus();
    int a = 0;
    int b = 0;
    float findArea() override;
    float findPerimeter() override;
    void setAB(int, int);
    int getA();
    int getB();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RHOMBUS_H
