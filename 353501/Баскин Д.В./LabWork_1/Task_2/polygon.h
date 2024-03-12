#ifndef POLYGON_H
#define POLYGON_H

#include "basicshape.h"

class Polygon: public BasicShape
{
public:
    Polygon();
    float area() override;
    float perimeter() override;
    void setPoints(QMouseEvent *me) override;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) override;
    QPoint centerOfWidget;
};

#endif // POLYGON_H
