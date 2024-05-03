#include "rhombus.h"



void Rhombus::setP(QMouseEvent *)
{
    //MouseNow=m->pos();
    points.clear();
        double deltax,deltay;
        deltax=qAbs(MouseNow.x()-MousePress.x());
        deltay=qAbs(MouseNow.y()-MousePress.y());
        double xp,yp,xn,yn;
        xp=MousePress.x();
        yp=MousePress.y();
        xn=MouseNow.x();
        yn=MouseNow.y();
        if(xp>xn)
        {
            qSwap(xn,xp);
        }
        if(yp<yn)
        {
            qSwap(yn,yp);
        }
        points.push_back({xp,yp});
        points.push_back({xn,yn});
        points.push_back({xp+deltax*2,yp});
        points.push_back({xn,yn+deltay*2});


}
