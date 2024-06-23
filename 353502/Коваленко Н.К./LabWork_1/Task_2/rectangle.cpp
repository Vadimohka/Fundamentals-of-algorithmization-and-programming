#include "rectangle.h"

rectangle::rectangle()
{

}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QBrush(QColor(0,255,255)));
    painter->drawRect(-length / 2,-width / 2,length,width);
}

float rectangle::area()
{
    return this->getScale() * this->getScale() * length * width;
}

float rectangle::perimeter()
{
    return (2 * getScale() * length + 2 * getScale() * width);
}
