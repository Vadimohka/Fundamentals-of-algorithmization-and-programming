#include "starEight.h"

void star8::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    n=8;
    SetStarP();
}
