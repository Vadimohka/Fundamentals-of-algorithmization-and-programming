#include "rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(-length / 2,-width / 2,length,width);
}

float Rectangle::area()
{
    return this->getScale() * this->getScale() * length * width;
}

float Rectangle::perimeter()
{
    return (2 * getScale() * length + 2 * getScale() * width);
}
