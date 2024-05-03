#include "rectangle.h"

qreal Rectangle::Area(const QVector<QPointF>&var) const
{
    // Расстояния между вершинами
    double a = d(var[0], var[1]);
    double b = d(var[1], var[2]);

    // Площадь прямоугольника
    double s = a * b;

    return s;

}

qreal Rectangle::Perimeter(const QVector<QPointF>&var) const
{
    // Расстояния между вершинами
    double a = d(var[0], var[1]);
    double b = d(var[1], var[2]);
    double c = d(var[2], var[3]);
    double e = d(var[3], var[0]);

    // Периметр прямоугольника
    double p = a + b + c + e;

    return p;
}

QPointF Rectangle::centerMass(const QVector<QPointF>&var) const
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


qreal Rectangle::d(const QPointF& p1,const QPointF& p2 )const{

    double dx=p2.x()-p1.x();
    double dy=p2.y()-p1.y();
    return std::sqrt(dx*dx+dy*dy);
}

