#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"shape.h"

class Triangle: public Shape
{
public:
    Triangle();
    float size=60;
    qreal x1;
    qreal y1;
    qreal x2;
    qreal y2;
    qreal x3;
    qreal y3;
    double valueC = 200;
    double valueB = 200;
    double valueA = 200;

    float area() override;
    float perimeter() override;

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* , QWidget* ) override;
    void updateSizeTriangleC(double arg1) override;
    void updateSizeTriangleB(double arg1) override;
    void updateSizeTriangleA(double arg1) override;
};

#endif // TRIANGLE_H
