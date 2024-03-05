#include "rectangle.h"

void Rectangle::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    points.clear();

    if(!Square)
    {
        points.push_back({(double)MousePress.x(),(double)MousePress.y()});
        points.push_back({(double)MouseNow.x(),(double)MousePress.y()});
        points.push_back({(double)MouseNow.x(),(double)MouseNow.y()});
        points.push_back({(double)MousePress.x(),(double)MouseNow.y()});

    }
    else
    {
        double deltax,deltay;
        deltax=qAbs(MouseNow.x()-MousePress.x());
        deltay=qAbs(MouseNow.y()-MousePress.y());
        /*
        qDebug()<<MousePress.x()<<" "<<MousePress.y();
        qDebug()<<MouseNow.x()<<" "<<MouseNow.y();
        */
        int ps_radius=qMax(deltax,deltay);
        //qDebug()<<ps_radius;
        double xp,yp,xn,yn;
        if(MouseNow.x()>=MousePress.x())
        {
            xp=MousePress.x();
            xn=xp+ps_radius;
        }
        else
        {
            xn=MousePress.x();
            xp=xn-ps_radius;
        }


        if(MouseNow.y()>=MousePress.y())
        {
            yp=MousePress.y();
            yn=yp+ps_radius;
        }
        else
        {
            yn=MousePress.y();
            yp=yn-ps_radius;
        }
        points.push_back({xp,yp});
        points.push_back({xn,yp});
        points.push_back({xn,yn});
        points.push_back({xp,yn});
    }

}


void Rectangle::reset(bool sp)
{
    size=last_size=1;
    points.clear();
    P=S=0;
    center={0,0};
    Square=false;
}


void Rectangle::make_sq()
{
    Square=true;
}
