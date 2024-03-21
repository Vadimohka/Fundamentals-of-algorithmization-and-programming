#include "wheel.h"

wheel::wheel() : circle()
{

}

void wheel::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
    this->angle = (double)(-x-y)/10;
}

void wheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(this->x - this->radius, this->y - this->radius, 2 * this->radius, 2 * this->radius);
    painter->drawLine(this->x + sin(angle) * this->radius, this->y + cos(angle) * this->radius,
                      this->x - sin(angle) * this->radius, this->y - cos(angle) * this->radius);
    painter->drawLine(this->x + sin(angle + acos(-1) / 2) * this->radius, this->y + cos(angle + acos(-1) / 2) * this->radius,
                      this->x - sin(angle + acos(-1) / 2) * this->radius, this->y - cos(angle + acos(-1) / 2) * this->radius);
}


