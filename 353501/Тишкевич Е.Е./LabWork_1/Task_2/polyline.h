#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"

class ShapePolyline : public Shape
{
public:
    ShapePolyline();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void getPoint(QPointF value)override;

    float sc=1.0;
    float rot=0;

    int xp=0;
    int yp = 0;

    void clear();

private:
    QPointF point;

    float area() override;
    float perim() override;

};

#endif // POLYLINE_H
