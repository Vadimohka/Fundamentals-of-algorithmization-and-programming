#include "star_8.h"

void star_8::setPoints(QMouseEvent *me) {
    mouseNow = me->pos();
    sumPoints(8);
}
