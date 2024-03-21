#include "figures.h"
figure::figure()=default;

void figure::move_figure()
{
    act=1;
    QPoint delta=MouseMoveNow-MouseMovePress;
    for(auto& a:points)
        a+=delta;
    if(!points.empty())
    center+=delta;
    MouseMovePress=MouseMoveNow;
}


void figure::reset(bool sp)
{
    size=last_size=1;
    points.clear();
    P=S;
    center={0,0};
    degree=0.0;
    showpoint=sp;
    qDebug()<<"Showpoint reset:"<<showpoint;

}


void figure::findSquare()
{
    S=0;
    if(points.size()>2){
        for(int i=1;i<points.size();i++)
            S+=points[i-1].x()*points[i].y()-points[i-1].y()*points[i].x();
        S+=points[0].y()*points.back().x()-points[0].x()*points.back().y();
        S=qAbs(S)/2;
    }
}


void figure::findPerimetr()
{
    P=0;
    if(points.size()>2){
        for(int i=1;i<points.size();i++)
            P+=qSqrt((points[i].x()-points[i-1].x())*(points[i].x()-points[i-1].x())+(points[i].y()-points[i-1].y())*(points[i].y()-points[i-1].y()));
    P+=qSqrt((points[0].x()-points.back().x())*(points[0].x()-points.back().x())+(points[0].y()-points.back().y())*(points[0].y()-points.back().y()));
}
}



void figure::setP(QMouseEvent *){}


void figure::SetAngle(int step)
{
    act=2;
    double alpha=step*M_PI/180.0;
    degree+=step;
    qDebug()<<"!!!!"<<points.size();

    for(auto& i:points)
    {
        i={(center.x()+qCos(alpha)*(i.x()-center.x())-qSin(alpha)*(i.y()-center.y())),center.y()+qSin(alpha)*(i.x()-center.x())+qCos(alpha)*(i.y()-center.y())};
    }

}


void figure::draw(QPainter *painter)
{
    QPolygonF poly;
    QPointF point;
    qDebug()<<"Point size: "<<points.size();

    for(auto& a:points)
    {
        point = {a.x(),a.y()};
        poly<<point;
        //qDebug()<<a.x();
    }


    findSquare();
    findPerimetr();
    if(points.size()==1)
    {
        painter->drawPoint(point);
    }
    else

    painter->drawPolygon(poly);
}


void figure::MousePressing(QMouseEvent *m)
{
    MousePress=m->pos();
    MouseNow=m->pos();

    qDebug()<<"MousePressing";

    degree=0;
    size=last_size=1;
}


void figure::MouseMoving(QMouseEvent *m)
{

    qDebug()<<"MouseMoving";

    MouseNow=m->pos();
    setP(m);
    updCenter();

    findPerimetr();
    findSquare();

}


void figure::MouseMovePressing(QMouseEvent *m)
{
    MouseMovePress=m->pos();
}


void figure::MouseMoveMoving(QMouseEvent *m)
{
    MouseMoveNow=m->pos();
    move_figure();
}


void figure::updCenter()
{
    if(points.size()==3)center={(points[0]+points[1]+points[2])/3};
    else
    {
        double xmi,ymi,xma,yma;
        xmi=xma=points[0].x();
        ymi=yma=points[0].y();
        for(auto& a:points)
        {
            xmi=qMin(a.x(),xmi);
            ymi=qMin(a.y(),ymi);
            xma=qMax(a.x(),xma);
            yma=qMax(a.y(),yma);
        }
        center={(xmi+xma)/2,(yma+ymi)/2};
    }
}


void figure::SizeEdit(bool Minus)
{
    act=2;
    last_size=size;
    qDebug()<<Minus<<" == "<<true;
    if(Minus&&size>0.02)
        size-=0.01;
    if(!Minus)
        size+=0.01;
    qDebug()<<size;
    resize();
}


void figure::resize()
{
    for(auto& i:points)
    {
        i=center+(i-center)/last_size*size;
    }
}

void figure::DrawP(QPainter *)
{

}


