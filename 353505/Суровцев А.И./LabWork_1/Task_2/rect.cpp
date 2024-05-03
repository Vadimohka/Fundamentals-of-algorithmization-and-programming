#include "rect.h"

Rect::Rect(){}

Rect::Rect(QPointF p, qreal a, qreal b)
{
    start_p = p;
    start_a = a;
    start_b = b;
    points.resize(4);
    points[0] = p;
    points[1] = QPointF(p.x() + a,p.y());
    points[2] = QPointF(p.x() + a,p.y() + b);
    points[3] = QPointF(p.x(),p.y() + b);
    length = a;
    width = b;
}

void Rect::SetStartParams()
{
    SetNewCoord(start_p, start_a, start_b);
}

void Rect::findSquareRect()
{
    squareRect = length * width;
}

qreal Rect::GetSquareRect()
{
    return squareRect;
}

void Rect::SetNewCoord(QPointF p, qreal a, qreal b)
{
    points.resize(4);
    points[0] = p;
    points[1] = QPointF(p.x() + a,p.y());
    points[2] = QPointF(p.x() + a,p.y() + b);
    points[3] = QPointF(p.x(),p.y() + b);
    length = a;
    width = b;
}
