#include "star8.h"

//star8::star8() {}
void star8::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    n=8;
    //qDebug()<<"Star5 Setp";
    SetStarP();
}
