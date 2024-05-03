#include "point.h"

point::point() {}

void point::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::red, 3));
    painter->drawPoint(xp,yp);
}

void point::updX(int num) {xp=num;}
void point::updY(int num) {yp=num;}

float point::area() {return 0;};
float point::perim() {return 0;};
