#include "star_6.h"

void star_6::setPoints(QMouseEvent *me) {
    mouseNow = me->pos();
    sumPoints(6);
}
