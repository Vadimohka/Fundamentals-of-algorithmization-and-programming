#include "star5.h"

void star5::setPoints(QMouseEvent *me) {
    mouseCurrentPos = me->pos();
    numOfPoints(5);
}
