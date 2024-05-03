#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape
{
public:
    Square(qreal side,  QGraphicsItem *parent = nullptr);

protected:
    void calculate_points();
    void resSide(qreal newside) override;
    qreal area() override;
    qreal perimeter() override;

private:
    qreal side;
};




#endif