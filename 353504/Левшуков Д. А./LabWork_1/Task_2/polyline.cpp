#include "polyline.h"


void Polyline::setP(QMouseEvent *m)
{
    MouseNow=m->pos();
    points.push_back(MouseNow);
}
void Polyline::draw(QPainter *painter)
{
    bool first=true;
    auto& last=center;//Need QPointF type

    if(points.size()>1)

    for(auto& i:points)
    {
        if(first)
        {
            last=i;
            first=false;
            continue;
        }
        painter->drawLine(i,last);
        last=i;
    }

    else if(points.size()==1)
        painter->drawPoint(points.back());

}

void Polyline::findSquare()
{
    findPerimetr();

    S=0;

}

void Polyline::findPerimetr()
{
    P=0;
    qDebug()<<"poly"<<points.size();
        if(points.size()>2){
            for(int i=1;i<points.size();i++)
                P+=qSqrt((points[i].x()-points[i-1].x())*(points[i].x()-points[i-1].x())+(points[i].y()-points[i-1].y())*(points[i].y()-points[i-1].y()));
            P+=qSqrt((points[0].x()-points.back().x())*(points[0].x()-points.back().x())+(points[0].y()-points.back().y())*(points[0].y()-points.back().y()));
        }
        P=P*2+2;
}
