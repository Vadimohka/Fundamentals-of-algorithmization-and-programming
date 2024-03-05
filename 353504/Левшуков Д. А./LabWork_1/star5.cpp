#include "star5.h"


void star5::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    n=5;
    //qDebug()<<"Star5 Setp";
    SetStarP();
}
