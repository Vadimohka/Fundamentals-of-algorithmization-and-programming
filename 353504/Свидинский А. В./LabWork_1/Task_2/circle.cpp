#include "circle.h"
#include <QBrush>
#include <cmath>
#include <QPen>

Circle::Circle(int diameter)
    : diameter(diameter)
{
    circle = new QGraphicsEllipseItem(0, 0, diameter, diameter);

    double centerX = diameter / 2;
    double centerY = diameter / 2;

    circle->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 0, 0, circle);
    centerOfMass->setPos(centerX, centerY);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    circle->setTransformOriginPoint(centerX, centerY);

    QPen pen(Qt::red);
    pen.setWidth(2);

    double lineLength = 10;

    line1 = new QGraphicsLineItem(centerX - lineLength / 2, centerY, centerX + lineLength / 2, centerY, circle);
    line1->setPen(pen);

    line2 = new QGraphicsLineItem(centerX, centerY - lineLength / 2, centerX, centerY + lineLength / 2, circle);
    line2->setPen(pen);

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);

    line1->setPen(outlinePen);
    line2->setPen(outlinePen);

    line1->hide();
    line2->hide();
}


QGraphicsEllipseItem* Circle::getItem()
{
    return circle;
}

QGraphicsEllipseItem* Circle::getCenterOfMass()
{
    return centerOfMass;
}

double Circle::getArea()
{
    return M_PI * pow(diameter / 2, 2);
}

double Circle::getPerimeter()
{
    return M_PI * diameter;
}

void Circle::moveCenterOfMass(double dx, double dy)
{
    circle->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}
