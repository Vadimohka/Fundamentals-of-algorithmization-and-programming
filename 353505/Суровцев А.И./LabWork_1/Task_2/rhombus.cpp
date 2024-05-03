#include "rhombus.h"

Rhombus::Rhombus(QPointF p, qreal a)
{
    start_p = p;
    start_a = a;
    SetNewCoord(p, a);
}

void Rhombus::SetNewCoord(QPointF p, qreal a)
{
    points.resize(4);
    points[0] = p;
    points[1] = QPointF(p.x() + a,p.y());
    qreal angle = 45;
    qreal newX = p.x() + a * cos(angle * M_PI / 180.0);
    qreal newY = p.y() + a * sin(angle * M_PI / 180.0);
    points[3] = QPointF(newX, newY);
    points[2] = QPointF(points[3].x()+a, points[3].y());
    size = a;
}

void Rhombus::SetStartParams()
{
    SetNewCoord(start_p, start_a);
}

void Rhombus::findSquareRomb()
{
    squareRomb = 1/2 * qPow(size, 2) * sin(45*M_PI/180);
}

qreal Rhombus::GetSquareRomb()
{
    return squareRomb;
}
