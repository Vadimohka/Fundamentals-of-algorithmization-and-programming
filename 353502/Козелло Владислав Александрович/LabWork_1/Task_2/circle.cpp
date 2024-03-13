#include "circle.h"

Circle::Circle()
{
    flag = 3;
}


void Circle::setPoints(QMouseEvent* event)
{
    nowPosition = event->pos();
    pointsCount = 2;
    points[0] = pressPosition;
    points[1] = nowPosition;
    double centerX = (points[0].x() + points[1].x()) / 2;
    double centerY = (points[0].y() + points[1].y()) / 2;
    if(centerX > centerY)
    {
        centerPoint = {centerX, points[0].y() + centerX - points[0].x()};
    }
    else
    {
        centerPoint = {points[0].x() + centerY - points[0].y(), centerY};
    }
    updateData();
}

void Circle::create(QPainter* painter)
{
    double diamX = qFabs(points[0].x() - points[1].x());
    double diamY = qFabs(points[0].y() - points[1].y());
    double diam = diamY > diamX ? diamY : diamX;

    QRectF ellipse(points[0].x(), points[0].y(), diam, diam);
    painter->drawEllipse(ellipse);
}


void Circle::updateData()
{
    if(points[1].x() > points[1].y())
    {
        square = PI * qPow(points[1].x() - centerPoint.x(), 2);
        perimetr = 2 * PI * (points[1].x() - centerPoint.x());
    }
    else
    {
        square = PI * qPow(points[1].y() - centerPoint.y(), 2);
        perimetr = 2 * PI * (points[1].y() - centerPoint.y());
    }
}


void Circle::setParameters(const double radius, const int k)
{
    points[1] = {points[0].x() + radius, points[0].y() + radius};
    double centerX = (points[0].x() + points[1].x()) / 2;
    double centerY = (points[0].y() + points[1].y()) / 2;
    if(centerX > centerY)
    {
        centerPoint = {centerX, points[0].y() + centerX - points[0].x()};
    }
    else
    {
        centerPoint = {points[0].x() + centerY - points[0].y(), centerY};
    }
    updateData();
}
