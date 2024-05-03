#include "hexagon.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>
#include <QPen>

Hexagon::Hexagon(int sideHexagon)
    : sideHexagon(sideHexagon)
{
    QPolygonF polygon;
    for (int i = 0; i < 6; ++i) {
        polygon << QPointF(sideHexagon * cos(i * M_PI / 3), sideHexagon * sin(i * M_PI / 3));
    }
    hexagon = new QGraphicsPolygonItem(polygon);

    double centerX = 0;
    double centerY = 0;

    hexagon->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 0, 0, hexagon);
    centerOfMass->setPos(centerX, centerY);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    hexagon->setTransformOriginPoint(centerX, centerY);

    QPen pen(Qt::red);
    pen.setWidth(2);
    double lineLength = 10;
    line1 = new QGraphicsLineItem(centerX - lineLength / 2, centerY, centerX + lineLength / 2, centerY, hexagon);
    line1->setPen(pen);
    line2 = new QGraphicsLineItem(centerX, centerY - lineLength / 2, centerX, centerY + lineLength / 2, hexagon);
    line2->setPen(pen);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    line1->setPen(outlinePen);
    line2->setPen(outlinePen);
    line1->hide();
    line2->hide();
}


QGraphicsPolygonItem* Hexagon::getItem()
{
    return hexagon;
}

QGraphicsEllipseItem* Hexagon::getCenterOfMass()
{
    return centerOfMass;
}

double Hexagon::getArea()
{
    return 3 * sqrt(3) / 2 * sideHexagon * sideHexagon;
}

double Hexagon::getPerimeter()
{
    return 6 * sideHexagon;
}

void Hexagon::moveCenterOfMass(double dx, double dy)
{
    hexagon->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}

