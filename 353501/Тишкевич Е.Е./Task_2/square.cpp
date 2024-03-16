#include "square.h"

Square::Square() {}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRect(-len*scale/2, -len*scale/2, len*scale, len*scale);
    painter->setPen(QPen(Qt::red, 3));
    painter->drawPoint(x,y);
    painter->setPen(QPen(Qt::darkGreen, 3));
    painter->drawPoint(0,0);
    painter->setPen(Qt::black);
}

float Square::perim()
{
    return 4 * len * this->getScale();
}

float Square::area()
{
    return this->getScale() *this->getScale() * len * len;
}
