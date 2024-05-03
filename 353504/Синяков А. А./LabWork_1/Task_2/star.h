#ifndef STAR_H
#define STAR_H
#include"geometry.h"
class Star:public Geometry
{
public:
    qreal d(const QPointF& p1,const QPointF& p2 )const override ;

};
class FivePointStar : public Star {
public:
    qreal Area(const QVector<QPointF>&var)const override;
    qreal Perimeter(const QVector<QPointF>&var)const override;
    QPointF centerMass(const QVector<QPointF>&var)const override;

    QVector<QPointF> var;

};

class SixPointStar : public Star {
public:
    qreal Area(const QVector<QPointF>&var)const override;
    qreal Perimeter(const QVector<QPointF>&var)const override;
    QPointF centerMass(const QVector<QPointF>&var)const override;

    QVector<QPointF> var;
};

class EightPointStar : public Star {
public:
    qreal Area(const QVector<QPointF>&var)const override;
    qreal Perimeter(const QVector<QPointF>&var)const override;
    QPointF centerMass(const QVector<QPointF>&var)const override;

    QVector<QPointF> var;
};
#endif // STAR_H
