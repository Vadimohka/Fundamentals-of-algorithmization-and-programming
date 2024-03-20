#include "movingrect.h"

movingRect::movingRect()
{

}

void movingRect::move()
{
    x += mx;
    y += my;
}

QRectF movingRect::boundingRect() const
{
    return QRectF(movingRect::x, movingRect::y, movingRect::w, movingRect::h);
}

void movingRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawRect(movingRect::x, movingRect::y, movingRect::w, movingRect::h);
}

