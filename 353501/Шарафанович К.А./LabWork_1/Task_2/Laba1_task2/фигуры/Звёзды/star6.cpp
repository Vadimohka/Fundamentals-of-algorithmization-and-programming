#include "star6.h"

void star6::setPoints(QMouseEvent *me) {
    mouseCurrentPos = me->pos();
    numOfPoints(6);
}
