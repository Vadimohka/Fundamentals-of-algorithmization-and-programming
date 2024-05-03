#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class Square : public Shape
{
public:
    Square(int sideSquare);

    QGraphicsRectItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    double getArea() override;
    double getPerimeter() override;
    void setSideSquare(int newSideSquare) { sideSquare = newSideSquare; }

private:
    QGraphicsRectItem *squareItem;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int sideSquare;
};

#endif // SQUARE_H
