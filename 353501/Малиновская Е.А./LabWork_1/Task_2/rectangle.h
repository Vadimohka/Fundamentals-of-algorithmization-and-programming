#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include "QPolygon"
class Rectangle : public Shape
{
    double height = 50;
    double width = 100;
public:

    qreal calculateArea() override;
    qreal calculatePerimeter() override;
    void calculatePoints() override;
    void changeHeight(double spinheight);
    void changeWidth(double spinwidth);
    Rectangle();
};

#endif // RECTANGLE_H
