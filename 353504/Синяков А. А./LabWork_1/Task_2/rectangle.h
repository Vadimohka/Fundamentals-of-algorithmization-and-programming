#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"geometry.h"
class Rectangle :public Geometry
{
public:
    qreal Area(const QVector<QPointF>&var)const override;
    qreal Perimeter(const QVector<QPointF>&var)const override;
    QPointF centerMass(const QVector<QPointF>&var)const override;
    qreal d(const QPointF& p1,const QPointF& p2 )const override ;
    QVector<QPointF> var;
};

#endif // RECTANGLE_H



