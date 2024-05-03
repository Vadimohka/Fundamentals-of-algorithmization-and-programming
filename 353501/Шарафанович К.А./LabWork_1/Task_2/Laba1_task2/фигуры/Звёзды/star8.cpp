#include "star8.h"

void star8::setPoints(QMouseEvent *me) {
    mouseCurrentPos = me->pos();
    numOfPoints(8);
}
