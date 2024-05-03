#ifndef HEXAGON_H
#define HEXAGON_H
#include "geometry.h"
class Hexagon : public Geometry
{
public:
    qreal Area(const QVector<QPointF>&var)const override;
    qreal Perimeter(const QVector<QPointF>&var)const override;
    QPointF centerMass(const QVector<QPointF>&var)const override;
    qreal d(const QPointF& p1,const QPointF& p2 )const override ;
    QVector<QPointF> var;
};

#endif // HEXAGON_H
