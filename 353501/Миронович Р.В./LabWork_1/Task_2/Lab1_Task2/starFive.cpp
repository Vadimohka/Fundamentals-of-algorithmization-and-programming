#include "starFive.h"


void star5::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    n=5;
    SetStarP();
}
