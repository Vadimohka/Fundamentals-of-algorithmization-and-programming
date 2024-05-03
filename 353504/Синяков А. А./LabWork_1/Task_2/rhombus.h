#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "geometry.h"
class Rhombus:public Geometry
{
public:
    qreal Area(const QVector<QPointF>&var)const override;
    qreal Perimeter(const QVector<QPointF>&var)const override;
    QPointF centerMass(const QVector<QPointF>&var)const override;
    qreal d(const QPointF& p1,const QPointF& p2 )const override ;
    QVector<QPointF> var;
};

#endif // RHOMBUS_H

