#include "star5.h"

enum { STAR_POINTS = 5 };

void star5::setPoints(QMouseEvent *me)
{
    mouseCurrentPos = me->pos();
    numOfPoints(STAR_POINTS);
}
