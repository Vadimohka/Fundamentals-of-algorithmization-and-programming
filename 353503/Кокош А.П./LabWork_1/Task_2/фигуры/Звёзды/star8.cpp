#include "star8.h"

enum { STAR_POINTS = 8 };

void star8::setPoints(QMouseEvent *me)
{
    mouseCurrentPos = me->pos();
    numOfPoints(STAR_POINTS);
}
