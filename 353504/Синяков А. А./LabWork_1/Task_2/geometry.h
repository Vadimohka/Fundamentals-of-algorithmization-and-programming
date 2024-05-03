#ifndef GEOMETRY_H
#define GEOMETRY_H
#include<QPointF>
#include<QVector>
#include<QPainter>
class Geometry
{
public:
    virtual qreal Area(const QVector<QPointF>&var)const = 0;
    virtual qreal Perimeter(const QVector<QPointF>&var)const = 0;
    virtual QPointF centerMass(const QVector<QPointF>&var)const=0;
    virtual qreal d(const QPointF& p1,const QPointF& p2 )const =0;
};

#endif // GEOMETRY_H
