#include "hexagon.h"



qreal Hexagon::Area(const QVector<QPointF>&var) const
{
    qreal area = 0.0;

    for (int i = 0, j = 1; i < var.size(); i++, j = (j + 1) % var.size()) {
        area += var[i].x() * (var[j].y() - var[(j + var.size() - 1) % var.size()].y());
    }

    area = 0.5 * std::abs(area);
    return area;
}

qreal Hexagon::Perimeter(const QVector<QPointF>&var) const
{
    double a=d(var[0],var[1]);
    double b=d(var[1],var[2]);
    double c=d(var[2],var[3]);
    double e=d(var[3],var[4]);
    double f=d(var[4],var[5]);
    double g=d(var[5],var[0]);

    double p=a+b+c+e+e+f+g;
    return p ;
}

QPointF Hexagon::centerMass(const QVector<QPointF>&var) const
{

    qreal totalX = 0.0;
    qreal totalY = 0.0;

    for (const QPointF& v : var) {
        totalX += v.x();
        totalY +=v.y();
    }

    qreal centerX = totalX / var.size();
    qreal centerY = totalY / var.size();

    return QPointF(centerX, centerY);

}


qreal Hexagon::d(const QPointF& p1,const QPointF& p2 )const{

    double dx=p2.x()-p1.x();
    double dy=p2.y()-p1.y();
    return std::sqrt(dx*dx+dy*dy);
}

