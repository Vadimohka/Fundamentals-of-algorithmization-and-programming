#include "square.h"

Square::Square(){}

void Square :: paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRect( -Size / 2 , -Size / 2 , Size , Size );

}

float Square :: Area()
{
    return this->getScale() * this->getScale() * Size * Size;
}

float Square :: Perimeter()
{
    return 4 * Size * this->getScale();
}
