#include "triangle.h"
#include "qgraphicsitem.h"
#include <QTimer>


qreal Triangle::Area(const QVector<QPointF>&var) const
{
    double a=d(var[0],var[1]);
    double b=d(var[1],var[2]);
    double c=d(var[2],var[0]);
    double s=(a+b+c)/2;
    return std::sqrt(s*(s-a)*(s-b)*(s-c));
}

qreal Triangle::Perimeter(const QVector<QPointF>&var) const
{
    double a=d(var[0],var[1]);
    double b=d(var[1],var[2]);
    double c=d(var[2],var[0]);
    double p=a+b+c;
    return p;
}

QPointF Triangle::centerMass(const QVector<QPointF>&var) const
{
    double centerX=0,centerY=0;
    for (const QPointF&v:var) {
        centerX+=v.x();
        centerY+=v.y();
    }
    return QPointF(centerX/3,centerY/3);
}


qreal Triangle::d(const QPointF& p1,const QPointF& p2 )const{

    double dx=p2.x()-p1.x();
    double dy=p2.y()-p1.y();
    return std::sqrt(dx*dx+dy*dy);
}
