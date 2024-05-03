#include "circle.h"

circle::circle() : QGraphicsItem(), x(0), y(0), radius(1)
{

}

void circle::setCircle(int x, int y, int radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}

void circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(this->x - this->radius, this->y - this->radius, 2 * this->radius, 2 * this->radius);
}

QRectF circle::boundingRect() const
{
    return QRectF(-this->radius,-this->radius,this->radius,this->radius);
}
