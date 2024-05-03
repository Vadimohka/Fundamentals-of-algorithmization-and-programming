#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure
{
public:
    Square();
    int a = 0;
    float findArea() override;
    float findPerimeter() override;
    void setA(int);
    int getA();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};


#endif // SQUARE_H
