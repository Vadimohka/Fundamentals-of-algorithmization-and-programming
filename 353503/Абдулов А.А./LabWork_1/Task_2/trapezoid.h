#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include"figure.h"

class Trapezoid: public Figure{
public:
    Trapezoid();
    float area() override;
    float perimeter() override;
    float b = 100;
    float c = 160;
    float h = 30;
private:
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // TRAPEZOID_H
