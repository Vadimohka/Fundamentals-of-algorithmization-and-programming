#include "figureTriangle.h"

void figureTriangle::setPoints(QMouseEvent *me) {
    if(points.size() == 3) points.clear();
    mouseNow = me->pos();
    points.push_back(mouseNow);
    if(points.size() == 3) {
        center = {(points[0] + points[1] + points[2]) / 3};
    }
}
