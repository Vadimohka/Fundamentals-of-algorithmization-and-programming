#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "geometry.h"
#include "qgraphicsitem.h"
#include <QVector>
#include <QPointF>
#include <QTimer>

class Triangle :  public Geometry
{

public:

    qreal Area(const QVector<QPointF>&var)const override;
    qreal Perimeter(const QVector<QPointF>&var)const override;
    QPointF centerMass(const QVector<QPointF>&var)const override;
    qreal d(const QPointF& p1,const QPointF& p2 )const override ;

    QVector<QPointF> var;


};

#endif // TRIANGLE_H
