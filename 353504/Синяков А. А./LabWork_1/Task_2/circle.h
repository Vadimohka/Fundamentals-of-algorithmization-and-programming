#ifndef CIRCLE_H
#define CIRCLE_H

#include "geometry.h"

class Circle : public Geometry
{
public:
    qreal Area(const QVector<QPointF>& var) const override;
    qreal Perimeter(const QVector<QPointF>&var)const override;
    QPointF centerMass(const QVector<QPointF>& var) const override;
    qreal radius(const QVector<QPointF>& var) const;
    qreal d(const QPointF& p1,const QPointF& p2 )const override ;
    QVector<QPointF> var;
};

#endif // CIRCLE_H
