#include "parallelogram.h"

Parallelogram::Parallelogram() {}

Parallelogram::Parallelogram(QPointF p, qreal a, qreal b)
{
    start_p = p;
    start_a = a;
    start_b = b;
    SetNewCoord(p, a, b);
}

void Parallelogram::SetNewCoord(QPointF p, qreal a, qreal b)
{
    points.resize(4);
    points[0] = p;
    points[1] = QPointF(p.x() + a,p.y());
    qreal angle = 45;
    qreal newX = p.x() + b * cos(angle * M_PI / 180.0);
    qreal newY = p.y() + b * sin(angle * M_PI / 180.0);
    points[3] = QPointF(newX, newY);
    points[2] = QPointF(points[3].x()+a, points[3].y());
}

void Parallelogram::SetStartParams()
{
    SetNewCoord(start_p, start_a, start_b);
}

void Parallelogram::findSquarePar()
{
    QPointF vector1 = points[1] - points[0];
    QPointF vector2 = points[3] - points[0];
    squarePar = qAbs(vector1.x() * vector2.y() - vector1.y() * vector2.x());
}

qreal Parallelogram::GetSquarePar()
{
    return squarePar;
}
