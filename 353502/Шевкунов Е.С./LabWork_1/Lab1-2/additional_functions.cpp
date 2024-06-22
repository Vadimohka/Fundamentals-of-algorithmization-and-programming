#include "additional_functions.h"


qreal dist(QPoint pointA, QPoint pointB)
{
    return qSqrt(qPow(pointB.x() - pointA.x(), 2) + qPow(pointB.y() - pointA.y(), 2));
}

qreal dist(QPointF pointA, QPointF pointB)
{
    return qSqrt(qPow(pointB.x() - pointA.x(), 2) + qPow(pointB.y() - pointA.y(), 2));
}


qreal triangleSquare(QPoint pointA, QPoint pointB, QPoint pointC)
{
    qreal semiperimeter = (dist(pointA, pointB) + dist(pointC, pointB) + dist(pointA, pointC)) / 2;
    return qSqrt(semiperimeter * (semiperimeter - dist(pointA, pointB)) * (semiperimeter - dist(pointA, pointC)) * (semiperimeter - dist(pointC, pointB)));
}

qreal triangleSquare(QPointF pointA, QPointF pointB, QPointF pointC)
{
    qreal semiperimeter = (dist(pointA, pointB) + dist(pointC, pointB) + dist(pointA, pointC)) / 2;
    return qSqrt(semiperimeter * (semiperimeter - dist(pointA, pointB)) * (semiperimeter - dist(pointA, pointC)) * (semiperimeter - dist(pointC, pointB)));
}


qreal polygonSquare(QPoint* points, short amnt)
{
    if (amnt < 3)
    {
        throw "At least three points are required.";
    }

    QPoint tPoint = (points[0] + points[1]) / 2;
    qreal square = 0;

    for (short i = 1; i < amnt; ++i)
    {
        square += triangleSquare(tPoint, points[i - 1], points[i]);
    }
    return square;
}

qreal polygonSquare(QPointF* points, short amnt)
{
    if (amnt < 3)
    {
        throw "At least three points are required.";
    }

    QPointF tPoint = (points[0] + points[1]) / 2;
    qreal square = 0;

    for (short i = 1; i < amnt; ++i)
    {
        square += triangleSquare(tPoint, points[i - 1], points[i]);
    }
    return square;
}

QPointF center_tr(QPointF pointA, QPointF pointB, QPointF pointC)
{
    return (pointA + pointB + pointC) / 3;
}

QPoint center_tr(QPoint pointA, QPoint pointB, QPoint pointC)
{
    return (pointA + pointB + pointC) / 3;
}
