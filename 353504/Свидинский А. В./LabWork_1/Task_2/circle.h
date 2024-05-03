#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <QGraphicsEllipseItem>

class Circle : public Shape
{
public:
    Circle(int diameter);

    QGraphicsEllipseItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setDiameter(int newDiameter) { diameter = newDiameter; }

private:
    QGraphicsEllipseItem *circle;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int diameter;
};

#endif // CIRCLE_H
