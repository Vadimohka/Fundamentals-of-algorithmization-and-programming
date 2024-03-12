#include "circle.h"

Circle::Circle()
{

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawEllipse(-radius / 2, -radius / 2,radius,radius);
}

float Circle::area()
{
    return this->getScale() * this->getScale() * M_PI * radius * radius;
}

float Circle::perimeter()
{
    return this->getScale() * 2 * M_PI * radius;
}

void Circle::setRadius(int value)
{
    this->radius = value;
    update();
}

float Circle::getRadius()
{
    return this->radius;
}
