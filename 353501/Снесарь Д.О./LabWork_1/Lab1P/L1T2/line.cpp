#include "line.h"


Line::Line(QPointF point, QPointF zeroPoint)
{
    center = point;
}

void Line::draw(QPainter *pntr)
{

    for(int i = 0; i < points.size() - 1; i++) {
        pntr->drawLine(points[i], points[i + 1]);
    }
}

double Line::getS()
{
    return 0;
}

double Line::getP()
{
    return 0;
}

void Line::setSize(QPointF nPoint)
{
    points.push_back(nPoint);
}
