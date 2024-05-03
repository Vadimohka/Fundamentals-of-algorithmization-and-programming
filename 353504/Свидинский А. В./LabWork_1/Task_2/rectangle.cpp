#include "rectangle.h"
#include <QBrush>
#include <QPen>

Rectangle::Rectangle(int width, int height)
    : width(width), height(height)
{
    rectangle = new QGraphicsRectItem(0, 0, width, height);
    rectangle->setPos(-rectangle->rect().width()/2, -rectangle->rect().height()/2);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 0, 0, rectangle);
    centerOfMass->setPos(width/2, height/2);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    rectangle->setTransformOriginPoint(width/2, height/2);

    QPen pen(Qt::red);
    pen.setWidth(2);

    double lineLength = 10;

    line1 = new QGraphicsLineItem(width/2 - lineLength / 2, height/2, width/2 + lineLength / 2, height/2, rectangle);
    line1->setPen(pen);

    line2 = new QGraphicsLineItem(width/2, height/2 - lineLength / 2, width/2, height/2 + lineLength / 2, rectangle);
    line2->setPen(pen);

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);

    line1->setPen(outlinePen);
    line2->setPen(outlinePen);

    line1->hide();
    line2->hide();
}

QGraphicsRectItem* Rectangle::getItem()
{
    return rectangle;
}

QGraphicsEllipseItem* Rectangle::getCenterOfMass()
{
    return centerOfMass;
}

double Rectangle::getArea()
{
    return width * height;
}

double Rectangle::getPerimeter()
{
    return 2 * (width + height);
}
