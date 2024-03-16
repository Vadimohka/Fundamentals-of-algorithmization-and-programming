#include "rectangle.h"

Rectangle::Rectangle(){}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRect( -Length / 2 , -Width / 2, Length , Width );
}

float Rectangle :: Area()
{
    return this->getScale() * this->getScale() * Length * Width;
}

float Rectangle :: Perimeter()
{
    return (2 * getScale() * Length + 2 * getScale() * Width);
}
