#include "star7.h"

enum { STAR_POINTS = 7 };

void star7::setPoints(QMouseEvent *me)
{
    mouseCurrentPos = me->pos();
    numOfPoints(STAR_POINTS);
}
