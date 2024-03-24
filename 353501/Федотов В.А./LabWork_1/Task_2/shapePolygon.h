#ifndef SHAPEPOLYGON_H
#define SHAPEPOLYGON_H

#include "shape.h"

class ShapePolygon : public Shape
{
public:
    ShapePolygon();

    //variables
    qreal side1, side2, side3, side4, side5, side6;

    //arrays
    QVector<QPointF> points;
    QVector<qreal> pointsX;
    QVector<qreal> pointsY;
    QVector<qreal> sides;

    //functions
    virtual void changeSide1(qreal value);
    virtual void changeSide2(qreal value);
    virtual void changeSide3(qreal value);

    virtual qreal area() override;
    virtual qreal perimeter() override;
};

#endif // SHAPEPOLYGON_H
