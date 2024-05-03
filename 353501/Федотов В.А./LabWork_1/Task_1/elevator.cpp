#include "elevator.h"

Elevator::Elevator() : Rectangle() {
    floor = 1;

    connect(this, &Elevator::floorChanged, this, &Elevator::handleFloorChange);

}

QRectF Elevator::boundingRect() const
{
    return QRectF(0, shiftY, 100, 250);
}

void Elevator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF rect = boundingRect();

    QPen pen(Qt::black);
    pen.setWidth(4);

    painter->setPen(pen);
    painter->drawRect(rect);
}


