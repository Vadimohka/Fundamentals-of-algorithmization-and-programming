#include "circle.h"
#include<QBrush>

void Circle::draw(QPainter *painter)
{
    qDebug()<<"Start draw circle..."<<showpoint;
    double deltax,deltay;
    deltax=qAbs(MouseNow.x()-MousePress.x());
    deltay=qAbs(MouseNow.y()-MousePress.y());
    qDebug()<<MousePress.x()<<" "<<MousePress.y();
    qDebug()<<MouseNow.x()<<" "<<MouseNow.y();
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
    center={(xp+xn)/2,(yn+yp)/2};
    radius=qAbs(xn-xp)*size/2;
    qDebug()<<"Radius: "<<radius<<"[Center]  x: "<<center.x()<<" y: "<<center.y();
    painter->drawEllipse(center,(xn-xp)*size/2,(yn-yp)*size/2);
    findSquare();
    findPerimetr();

    if(radius>0)
    {
        if(act==0)
        {
            qDebug()<<"+ point";
            points.clear();
            points.push_back({center.x()+radius,center.y()});
        }
        NoCircle=false;
    }
    else NoCircle=true,points.clear();
    //sp_status();
    qDebug()<<points.size()<<" - point puted "<<showpoint;


    if(showpoint)
    {
        DrawP(painter);
    }
}

void Circle::move_figure()
{
    qDebug()<<"Circle try move";
    if(!NoCircle){
        QPoint delta=MouseMoveNow-MouseMovePress;
        MousePress+=delta;
        MouseNow+=delta;
        for(auto& a:points)
            a+=delta;
        if(!points.empty())
            center+=delta;
        MouseMovePress=MouseMoveNow;
    }
}


void Circle::findSquare()
{
    qDebug()<<radius<<"in square";
    S=M_PI*radius*radius;
}


void Circle::findPerimetr()
{
    P=M_PI*radius*2;
}


void Circle::DrawP(QPainter *painter)//work
{
    if(points.empty())return;
    QPen pen;
    pen.setColor(QColor("red"));
    pen.setWidth(5);
    painter->setPen(pen);
    //qDebug()<<points.front().x()<<" "<<points.front().y()<<"POINT";
    painter->drawPoint(points.front());
}

void Circle::updCenter()
{

}


void Circle::reset(bool sp)
{
    NoCircle=true;
    size=last_size=1;
    MouseMoveNow=MouseMovePress=MouseNow=MousePress={0,0};
    P=S=0;
    center={0,0};
    points.clear();
    showpoint=sp;
}
