#include "line.h"

Line::Line()
{

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPoint(1000,1000);
}
