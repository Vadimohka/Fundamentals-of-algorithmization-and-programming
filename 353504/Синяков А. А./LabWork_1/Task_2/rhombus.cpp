#include "rhombus.h"

qreal Rhombus::Area(const QVector<QPointF>&var) const
{
    double d1=d(var[0], var[2]);
    double d2=d(var[1], var[3]);
    double s=(d1*d2)/2;
    return s;
}

qreal Rhombus::Perimeter(const QVector<QPointF>&var) const
{
    double a=d(var[0],var[1]);

    double p=a*4;
    return p ;
}

QPointF Rhombus::centerMass(const QVector<QPointF>&var) const
{
    double centerX = 0, centerY = 0;
    for (const QPointF& v : var) {
        centerX += v.x();
        centerY += v.y();
    }
    return QPointF(centerX / var.size(), centerY / var.size());
}


qreal Rhombus::d(const QPointF& p1,const QPointF& p2 )const{

    double dx=p2.x()-p1.x();
    double dy=p2.y()-p1.y();
    return std::sqrt(dx*dx+dy*dy);
}
