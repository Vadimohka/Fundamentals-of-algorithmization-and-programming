#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "shape.h"
#include <QGraphicsPolygonItem>

class Rhombus : public Shape
{
public:
    Rhombus(int diagonal1, int diagonal2);

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setDiagonals(int newDiagonal1, int newDiagonal2) { diagonal1 = newDiagonal1; diagonal2 = newDiagonal2; }
    int getDiagonal1() const { return diagonal1; }
    int getDiagonal2() const { return diagonal2; }

private:
    QGraphicsPolygonItem *rhombus;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int diagonal1;
    int diagonal2;
};

#endif // RHOMBUS_H
