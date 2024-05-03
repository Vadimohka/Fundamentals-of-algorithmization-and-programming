#include "yourdrawing.h"

YourDrawing::YourDrawing(QVector<QPointF> p)
{
    SetPoints(p);
    start_points = p;
}

void YourDrawing::SetStartParams()
{
    SetPoints(start_points);
}

void YourDrawing::draw(QPainter *painter)
{
    if (!points.empty()) {
        painter->drawPolyline(points);
    }
}

QVector<QPointF> YourDrawing::getStartParams()
{
    return start_points;
}
