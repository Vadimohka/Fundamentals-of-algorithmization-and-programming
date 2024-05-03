#include "rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(-length / 2, -width / 2, length, width);
}

float Rectangle::area()
{
    return this->getScale() * this->getScale() * length * width;
}

float Rectangle::perimeter()
{
    return this->getScale() * 2 * (length + width);
}

void Rectangle::setLength(int value)
{
    this->length = value;
    update();
}

void Rectangle::setWidth(int value)
{
    this->width = value;
    update();
}

float Rectangle::getLength()
{
    return this->length;
}

float Rectangle::getWidth()
{
    return this->width;
}
