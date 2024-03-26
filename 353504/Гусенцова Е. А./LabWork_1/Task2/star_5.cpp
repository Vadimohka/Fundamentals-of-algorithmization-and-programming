#include "star_5.h"

void star_5::setPoints(QMouseEvent *me) {
    mouseNow = me->pos();
    sumPoints(5);
}
