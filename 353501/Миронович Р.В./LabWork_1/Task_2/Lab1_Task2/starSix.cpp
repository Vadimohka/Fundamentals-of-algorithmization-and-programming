#include "starSix.h"

void star6::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    n=6;
    SetStarP();
}
