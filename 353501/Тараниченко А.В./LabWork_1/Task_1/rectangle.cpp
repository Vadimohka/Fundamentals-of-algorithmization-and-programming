#include "rectangle.h"

Rectangle::Rectangle()
{

}

QRectF Rectangle::boundingRect() const
{
    return QRectF(0,0,0,0);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawRect(this->x, this->y, this->w, this->h);

    painter->setBrush(Qt::white);

}
