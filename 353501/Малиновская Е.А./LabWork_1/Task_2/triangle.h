#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape
{
    double side1 = 50;
    double side2 = 50;
    double side3 = 50;

public:
    //void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    qreal calculateArea() override;
    qreal calculatePerimeter() override;
    void changeSide1(double spinside1);
    void changeSide2(double spinside2);
    void changeSide3(double spinside3);
    void calculatePoints() override;
    Triangle();
};

#endif // TRIANGLE_H
