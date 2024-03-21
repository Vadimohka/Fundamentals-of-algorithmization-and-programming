#include "stars.h"


void stars::SetStarP()
{
    qDebug()<<"Star Type: "<<n;
    points.clear();
    double deltax,deltay;
    deltax=qAbs(MouseNow.x()-MousePress.x());
    deltay=qAbs(MouseNow.y()-MousePress.y());
    double xp,yp,xn,yn,xc,yc;
    xp=MousePress.x();
    yp=MousePress.y();
    xn=MouseNow.x();
    yn=MouseNow.y();
    xc=(xp+xn)/2;
    yc=(yp+yn)/2;
    for(int i=0;i<n;i++)
    {
        points.push_back({xc-deltax*qSin(2*M_PI/n*i),yc-deltay*qCos(2*M_PI/n*i)});//outpoint
        points.push_back({xc-deltax/2*qSin(2*M_PI/n*(i+0.5)),yc-deltay/2*qCos(2*M_PI/n*(i+0.5))});
    }
}
