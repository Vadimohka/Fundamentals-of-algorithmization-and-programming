#include "star6.h"

void star6::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    n=6;
    //qDebug()<<"Star5 Setp";
    SetStarP();
}
