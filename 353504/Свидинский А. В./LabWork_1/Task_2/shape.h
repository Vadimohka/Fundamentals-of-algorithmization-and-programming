#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>

class Shape
{
public:
    virtual ~Shape() {}

    virtual QGraphicsItem* getItem() = 0;
    virtual QGraphicsEllipseItem* getCenterOfMass() = 0;
    virtual QGraphicsLineItem* getLine1() = 0;
    virtual QGraphicsLineItem* getLine2() = 0;
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

#endif // SHAPE_H
