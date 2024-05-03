#include "triangle.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>
#include <QPen>

Triangle::Triangle(int side)
    : side(side)
{
    QPolygonF polygon;
    polygon << QPointF(0, 0) << QPointF(side, 0) << QPointF(side / 2, sqrt(3) * side / 2);
    triangle = new QGraphicsPolygonItem(polygon);

    double centerX = (polygon[0].x() + polygon[1].x() + polygon[2].x()) / 3;
    double centerY = (polygon[0].y() + polygon[1].y() + polygon[2].y()) / 3;

    triangle->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 0, 0, triangle);
    centerOfMass->setPos(centerX, centerY);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    triangle->setTransformOriginPoint(centerX, centerY);

    QPen pen(Qt::red);
    pen.setWidth(2);
    double lineLength = 10;
    line1 = new QGraphicsLineItem(centerX - lineLength / 2, centerY, centerX + lineLength / 2, centerY, triangle);
    line1->setPen(pen);
    line2 = new QGraphicsLineItem(centerX, centerY - lineLength / 2, centerX, centerY + lineLength / 2, triangle);
    line2->setPen(pen);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    line1->setPen(outlinePen);
    line2->setPen(outlinePen);
    line1->hide();
    line2->hide();
}


QGraphicsPolygonItem* Triangle::getItem()
{
    return triangle;
}

QGraphicsEllipseItem* Triangle::getCenterOfMass()
{
    return centerOfMass;
}

double Triangle::getArea()
{
    return sqrt(3) / 4 * side * side;
}

double Triangle::getPerimeter()
{
    return 3 * side;
}

void Triangle::moveCenterOfMass(double dx, double dy)
{
    triangle->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}
