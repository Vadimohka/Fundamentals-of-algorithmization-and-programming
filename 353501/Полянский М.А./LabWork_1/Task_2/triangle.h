#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <cmath>
#include <QPointF>
class Triangle : public Shape
{
public:
    Triangle(qreal side1, qreal side2, qreal side3, QGraphicsItem *parent = nullptr);
    void resizeTriangle1(qreal side) override;
    void resizeTriangle2(qreal side) override;
    void resizeTriangle3(qreal side) override;
    
protected:
    void calculate_points();
    qreal area() override;
    qreal perimeter() override;

private:
    qreal side1;
    qreal side2;
    qreal side3;
    QVector<qreal> pointsx;
    QVector<qreal> pointsy;
};

#endif // TRIANGLE_H
