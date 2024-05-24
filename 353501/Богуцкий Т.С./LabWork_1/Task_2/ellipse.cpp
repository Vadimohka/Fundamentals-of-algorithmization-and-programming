#include "ellipse.h"

ellipse::ellipse()
{

}

float ellipse::area()
{
    return this->getScale() * this->getScale() * M_PI * radius1 * radius2;
}

float ellipse::perimeter()
{
    return this->getScale() * this->getScale() * 4 * (M_PI*radius1*radius2 + radius1-radius2)/(radius1 + radius2);
}

void ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse(-radius1 / 2, -radius2 / 2,radius1,radius2);
}
