#include "star7.h"

void star7::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    n=7;
    //qDebug()<<"Star5 Setp";
    SetStarP();
}
