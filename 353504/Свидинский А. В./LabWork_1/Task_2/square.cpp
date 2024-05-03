#include "square.h"
#include <QBrush>
#include <QPen>

Square::Square(int sideSquare)
    : sideSquare(sideSquare)
{
    squareItem = new QGraphicsRectItem(0, 0, sideSquare, sideSquare);
    squareItem->setPos(-squareItem->rect().width()/2, -squareItem->rect().height()/2);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 0, 0, squareItem);
    centerOfMass->setPos(sideSquare/2, sideSquare/2);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    squareItem->setTransformOriginPoint(sideSquare/2, sideSquare/2);

    QPen pen(Qt::red);
    pen.setWidth(2);

    double lineLength = 10;

    line1 = new QGraphicsLineItem(sideSquare/2 - lineLength / 2, sideSquare/2, sideSquare/2 + lineLength / 2, sideSquare/2, squareItem);
    line1->setPen(pen);

    line2 = new QGraphicsLineItem(sideSquare/2, sideSquare/2 - lineLength / 2, sideSquare/2, sideSquare/2 + lineLength / 2, squareItem);
    line2->setPen(pen);

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);

    line1->setPen(outlinePen);
    line2->setPen(outlinePen);

    line1->hide();
    line2->hide();
}


double Square::getArea()
{
    return sideSquare * sideSquare;
}

double Square::getPerimeter()
{
    return 4 * sideSquare;
}

QGraphicsRectItem* Square::getItem()
{
    return squareItem;
}

QGraphicsEllipseItem* Square::getCenterOfMass()
{
    return centerOfMass;
}
