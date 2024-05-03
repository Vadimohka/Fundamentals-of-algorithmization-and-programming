#include "star7.h"

void star7::setPoints(QMouseEvent *me) {
    mouseCurrentPos = me->pos();
    numOfPoints(7);
}
