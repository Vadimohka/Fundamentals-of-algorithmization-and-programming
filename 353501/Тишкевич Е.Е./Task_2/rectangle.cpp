#include "rectangle.h"

Rectangle::Rectangle(){}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRect(-len*scale / 2,-wid*scale / 2,len*scale,wid*scale);
    painter->setPen(QPen(Qt::red, 3));
    painter->drawPoint(QPointF(x,y));
    painter->setPen(QPen(Qt::darkGreen, 3));
    painter->drawPoint(0,0);
    painter->setPen(Qt::black);
}

float Rectangle::area()
{
    return this->getScale() * this->getScale() * len * wid;
}

float Rectangle::perim()
{
    return (2 * this->getScale() * len + 2 * this->getScale() * wid);
}

float Rectangle::getWid()
{
    return wid;
}

float Rectangle::getHei()
{
    return len;
}

void Rectangle::setHei(float num)
{
    len=num;
}

void Rectangle::setWid(float num)
{
    wid=num;
}
