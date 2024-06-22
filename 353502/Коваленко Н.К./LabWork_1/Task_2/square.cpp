#include "square.h"

Square::Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QBrush(QColor(0,255,255)));
    painter->drawRect(-size / 2, -size / 2, size, size);
}

float Square::area()
{
    return this->getScale() *this->getScale() * size * size;
}

float Square::perimeter()
{
    return 4 * size * this->getScale();
}
