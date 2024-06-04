#include "line.h"

Line::Line(){

}

void Line::setPoints(QMouseEvent *me){
    mouseNow = me->pos();
    points.push_back(mouseNow);
}

