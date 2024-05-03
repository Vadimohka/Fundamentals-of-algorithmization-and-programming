#include "rhombus.h"
#include <QBrush>
#include <QPolygonF>
#include <QPen>
#include <cmath>

Rhombus::Rhombus(int diagonal1, int diagonal2)
    : diagonal1(diagonal1), diagonal2(diagonal2)
{
    QPolygonF polygon;
    polygon << QPointF(0, 0) << QPointF(diagonal1 / 2, diagonal2 / 2) << QPointF(diagonal1, 0) << QPointF(diagonal1 / 2, -diagonal2 / 2);
    rhombus = new QGraphicsPolygonItem(polygon);

    double centerX = (polygon[0].x() + polygon[1].x() + polygon[2].x() + polygon[3].x()) / 4;
    double centerY = (polygon[0].y() + polygon[1].y() + polygon[2].y() + polygon[3].y()) / 4;

    rhombus->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 0, 0, rhombus);
    centerOfMass->setPos(centerX, centerY);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    rhombus->setTransformOriginPoint(centerX, centerY);

    QPen pen(Qt::red);
    pen.setWidth(2);

    double lineLength = 10;

    line1 = new QGraphicsLineItem(centerX - lineLength / 2, centerY, centerX + lineLength / 2, centerY, rhombus);
    line1->setPen(pen);

    line2 = new QGraphicsLineItem(centerX, centerY - lineLength / 2, centerX, centerY + lineLength / 2, rhombus);
    line2->setPen(pen);

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);

    line1->setPen(outlinePen);
    line2->setPen(outlinePen);

    line1->hide();
    line2->hide();
}


QGraphicsPolygonItem* Rhombus::getItem()
{
    return rhombus;
}

QGraphicsEllipseItem* Rhombus::getCenterOfMass()
{
    return centerOfMass;
}

double Rhombus::getArea()
{
    return 0.5 * diagonal1 * diagonal2;
}

double Rhombus::getPerimeter()
{
    return 2 * sqrt(pow(diagonal1 / 2, 2) + pow(diagonal2 / 2, 2));
}

void Rhombus::moveCenterOfMass(double dx, double dy)
{
    rhombus->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}


