#include "soldat.h"

Soldat::Soldat()
{

}

QRectF Soldat::boundingRect() const
{
    return QRectF(-350,-300,700,600);
}

void Soldat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawRect(-300,0, 60, 120);
    painter->drawRect(-300,120, 25, 100);
    painter->drawRect(-265,120, 25, 100);
    painter->drawRect(-285,-30, 30,30);
    painter->drawRect(-240,0,25,100);
    painter->drawRect(-325, 0, 25, 100);

    painter->setBrush(Qt::white);

}

void Soldat::advance(int phase)
{
    moveBy(0.2,0);
}

