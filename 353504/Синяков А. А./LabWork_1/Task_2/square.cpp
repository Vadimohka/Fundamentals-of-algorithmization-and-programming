#include "square.h"

qreal Square::Area(const QVector<QPointF>&var) const
{
    double a=d(var[0],var[1]);
    double s=a*a;
    return s;
}

qreal Square::Perimeter(const QVector<QPointF>&var) const
{
    double a=d(var[0],var[1]);
    double p=4*a;
    return p ;
}

QPointF Square::centerMass(const QVector<QPointF>&var) const
{
    double centerX = 0, centerY = 0;

    for (const QPointF& v : var) {
        centerX += v.x();
        centerY += v.y();
    }

    centerX /= var.size();
    centerY /= var.size();

    return QPointF(centerX, centerY);
}


qreal Square::d(const QPointF& p1,const QPointF& p2 )const{

    double dx=p2.x()-p1.x();
    double dy=p2.y()-p1.y();
    return std::sqrt(dx*dx+dy*dy);
}


