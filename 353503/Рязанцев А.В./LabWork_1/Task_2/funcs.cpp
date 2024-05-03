#include "funcs.h"

qreal Dist(QPointF a, QPointF b)
{
    return qSqrt(qPow(b.x() - a.x(), 2) + qPow(b.y() - a.y(),2));
}

qreal Dist(qreal x_1, qreal x_2)
{
    return x_2 - x_1;
}
