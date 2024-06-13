#include "star6.h"

enum { STAR_POINTS = 6 };

void star6::setPoints(QMouseEvent *me)
{
    mouseCurrentPos = me->pos();
    numOfPoints(STAR_POINTS);
}
