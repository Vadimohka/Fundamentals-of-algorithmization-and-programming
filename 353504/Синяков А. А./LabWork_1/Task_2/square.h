#ifndef SQUARE_H
#define SQUARE_H
#include"geometry.h"
class Square:public Geometry
{
public:
    qreal Area(const QVector<QPointF>&var)const override;
    qreal Perimeter(const QVector<QPointF>&var)const override;
    QPointF centerMass(const QVector<QPointF>&var)const override;
    qreal d(const QPointF& p1,const QPointF& p2 )const override ;
    QVector<QPointF> var;
};

#endif // SQUARE_H
