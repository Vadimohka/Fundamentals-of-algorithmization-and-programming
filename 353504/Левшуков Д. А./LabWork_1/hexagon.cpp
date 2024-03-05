#include "hexagon.h"


void Hexagon::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    points.clear();
    double xp,yp,xn,yn,deltax,deltay; //p - press, n - now, h^2
    xp=MousePress.x();
    yp=MousePress.y();
    xn=MouseNow.x();
    yn=MouseNow.y();
    //Range between xp and xn is down of trapecy(TRAPECII)
    deltax=xn-xp;
    deltay=yn-yp;
    //qDebug()<<"Deltas: "<<deltax<<" "<<deltay;
    //qDebug()<<MousePress.x()<<" "<<MousePress.y()<<" "<<MouseNow.x()<<" "<<MouseNow.y();
    //points.push_back({xp,yp});
    //points.push_back({xp,yp-deltay});
    //h2=
    //double h=qSqrt()
    double xc=(xp+xn)/2,yc=(yp+yn)/2;
    //points.push_back({xc-deltax/2*qSin(M_PI/3*2)+2,xc-deltay/2*qCos(M_PI/3*2)+2});
    //points.push_back({xn,yn});
    //points.push_back({xn,yn+deltay});
    //points.push_back({xc-deltax/2*qSin(M_PI/3*5)+5,xc-deltay/2*qCos(M_PI/3*5)+5});

    for(int i=0;i<6;i++)
    {
        points.push_back({xc-deltax*qSin(M_PI/3*i)+i,yc-deltay*qCos(M_PI/3*i)+i});//120*i
        //qDebug()<<points.back();
    }
    //points.push_back({xc,yc});

}
