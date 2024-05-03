#include "center.h"

Center::Center(QGraphicsItem *parent) : QGraphicsObject(parent){

}

Center::~Center()
{

}

QRectF Center::boundingRect() const
{
    return QRectF(-5, -5, 10, 10);
}

void Center::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::red, 1));
    painter->setBrush(QBrush(Qt::red));
    painter->drawEllipse(0, 0, 3, 3);
}
