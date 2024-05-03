#include "sixstar.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>
#include <QPen>

SixStar::SixStar(int sradius)
    : sradius(sradius)
{
    QPolygonF polygon;
    for (int i = 0; i < 12; ++i) {
        double r = (i % 2 == 0) ? sradius : sradius / 2.0;
        polygon << QPointF(r * cos(i * M_PI / 6), r * sin(i * M_PI / 6));
    }
    sstar = new QGraphicsPolygonItem(polygon);

    double centerX = 0;
    double centerY = 0;

    sstar->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 0, 0, sstar);
    centerOfMass->setPos(centerX, centerY);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    sstar->setTransformOriginPoint(centerX, centerY);

    QPen pen(Qt::red);
    pen.setWidth(2);
    double lineLength = 10;
    line1 = new QGraphicsLineItem(centerX - lineLength / 2, centerY, centerX + lineLength / 2, centerY, sstar);
    line1->setPen(pen);
    line2 = new QGraphicsLineItem(centerX, centerY - lineLength / 2, centerX, centerY + lineLength / 2, sstar);
    line2->setPen(pen);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    line1->setPen(outlinePen);
    line2->setPen(outlinePen);
    line1->hide();
    line2->hide();
}

QGraphicsPolygonItem* SixStar::getItem()
{
    return sstar;
}

QGraphicsEllipseItem* SixStar::getCenterOfMass()
{
    return centerOfMass;
}

double SixStar::getArea()
{
    return 3 * sqrt(3) / 2 * (sradius) * (sradius);
}

double SixStar::getPerimeter()
{
    return 12 * (sradius) * sin(M_PI / 6);
}

void SixStar::moveCenterOfMass(double dx, double dy)
{
    sstar->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}
