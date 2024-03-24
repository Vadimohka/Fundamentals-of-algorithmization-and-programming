#ifndef SHAPEPOLYLINE_H
#define SHAPEPOLYLINE_H

#include "shape.h"

class ShapePolyline : public Shape
{
public:
    ShapePolyline();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void getPoint(QPointF value);

private:
    QPointF point;

    qreal area() override;
    qreal perimeter() override;

    void clear() override;
};

#endif // SHAPEPOLYLINE_H
