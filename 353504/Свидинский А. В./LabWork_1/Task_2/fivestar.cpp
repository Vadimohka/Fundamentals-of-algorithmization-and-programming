#include "fivestar.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>
#include <QPen>

FiveStar::FiveStar(int fradius)
    : fradius(fradius)
{
    QPolygonF polygon;
    for (int i = 0; i < 10; ++i) {
        double r = (i % 2 == 0) ? fradius : fradius / 2.0;
        polygon << QPointF(r * cos(i * M_PI / 5), r * sin(i * M_PI / 5));
    }
    fstar = new QGraphicsPolygonItem(polygon);

    double centerX = 0;
    double centerY = 0;

    fstar->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 0, 0, fstar);
    centerOfMass->setPos(centerX, centerY);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    fstar->setTransformOriginPoint(centerX, centerY);

    QPen pen(Qt::red);
    pen.setWidth(2);
    double lineLength = 10;
    line1 = new QGraphicsLineItem(centerX - lineLength / 2, centerY, centerX + lineLength / 2, centerY, fstar);
    line1->setPen(pen);
    line2 = new QGraphicsLineItem(centerX, centerY - lineLength / 2, centerX, centerY + lineLength / 2, fstar);
    line2->setPen(pen);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    line1->setPen(outlinePen);
    line2->setPen(outlinePen);
    line1->hide();
    line2->hide();
}


QGraphicsPolygonItem* FiveStar::getItem()
{
    return fstar;
}

QGraphicsEllipseItem* FiveStar::getCenterOfMass()
{
    return centerOfMass;
}

double FiveStar::getArea()
{
    return 5.0 / 4.0 * (fradius) * (fradius) * tan(M_PI / 5);
}

double FiveStar::getPerimeter()
{
    return 10 * (fradius) * sin(M_PI / 5);
}

void FiveStar::moveCenterOfMass(double dx, double dy)
{
    fstar->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}

