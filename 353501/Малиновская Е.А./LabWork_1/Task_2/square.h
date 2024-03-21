#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
class Square : public Shape
{
    double side = 50;
public:
    qreal calculateArea() override;
    qreal calculatePerimeter() override;
    void calculatePoints() override;
    void changeSide(double spinside);
    Square();
};

#endif // SQUARE_H
