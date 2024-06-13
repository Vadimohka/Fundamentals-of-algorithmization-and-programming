#include "star_7.h"

void star_7::setPoints(QMouseEvent *me) {
    mouseNow = me->pos();
    sumPoints(7);
}
