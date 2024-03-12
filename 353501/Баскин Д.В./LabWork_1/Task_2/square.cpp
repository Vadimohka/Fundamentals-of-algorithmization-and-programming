#include "square.h"

Square::Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(-side / 2, -side / 2, side, side);
}

float Square::area()
{
    return this->getScale() * this->getScale() * side * side;
}

float Square::perimeter()
{
    return this->getScale() * 4 * side;
}

void Square::setSide(int value)
{
    this->side = value;
    update();
}

float Square::getSide()
{
    return this->side;
}
