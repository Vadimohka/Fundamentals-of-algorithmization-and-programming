#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "par_polygon.h"
class Parallelogram : public par_polygon
{
public:
    Parallelogram();
    Parallelogram(QPointF p, qreal a, qreal b);
    void SetNewCoord(QPointF p, qreal a, qreal b);
    void SetStartParams();
    void findSquarePar();
    qreal GetSquarePar();
protected:
    qreal squarePar = 0;
    QPointF start_p;
    qreal start_a;
    qreal start_b;
};

#endif // PARALLELOGRAM_H
