#include "square.h"

Square::Square(QPointF p, qreal a)
{
    start_p = p;
    start_a = a;
    points.resize(4);
    points[0] = p;
    points[1] = QPointF(p.x() + a,p.y());
    points[2] = QPointF(p.x() + a,p.y() + a);
    points[3] = QPointF(p.x(),p.y() + a);
    size = a;
}

void Square::SetStartParams()
{
    SetNewCoord(start_p, start_a);
}

void Square::findAreaSquare()
{
    areaSquare = size * size;
}

qreal Square::GetAreaSquare()
{
    return areaSquare;
}

void Square::SetNewCoord(QPointF p, qreal a)
{
    points.resize(4);
    points[0] = p;
    points[1] = QPointF(p.x() + a,p.y());
    points[2] = QPointF(p.x() + a,p.y() + a);
    points[3] = QPointF(p.x(),p.y() + a);
    size = a;
}
