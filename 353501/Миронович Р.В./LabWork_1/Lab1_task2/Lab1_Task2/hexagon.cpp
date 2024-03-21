#include "hexagon.h"


void Hexagon::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    points.clear();
    double xp,yp,xn,yn,deltax,deltay;
    xp=MousePress.x();
    yp=MousePress.y();
    xn=MouseNow.x();
    yn=MouseNow.y();
    deltax=xn-xp;
    deltay=yn-yp;
    double xc=(xp+xn)/2,yc=(yp+yn)/2;

    for(int i=0;i<6;i++)
    {
        points.push_back({xc-deltax*qSin(M_PI/3*i)+i,yc-deltay*qCos(M_PI/3*i)+i});
    }

}
