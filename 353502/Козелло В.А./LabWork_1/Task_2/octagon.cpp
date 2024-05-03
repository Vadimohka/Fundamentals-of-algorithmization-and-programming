#include "octagon.h"

Octagon::Octagon()
{
    flag = 10;
}


void Octagon::setPoints(QMouseEvent* event)
{
    nowPosition = event->pos();
    pointsCount = 8;

    double dif = distance(nowPosition, pressPosition);
    dify = nowPosition.y() - pressPosition.y();
    difx = nowPosition.x() - pressPosition.x();

    double angle = qAtan(dify/difx);

    for(int i = 0; i < pointsCount; i++)
    {
        points[i] = {dif * qCos(angle) + pressPosition.x(), dif * qSin(angle) + pressPosition.y()};
        angle += (2 * PI / pointsCount);
    }
    centerPoint = pressPosition;
    updateData();
}


void Octagon::updateData()
{
    double a = distance(points[0], points[1]);
    square = a * a * qSqrt(3) / 4;
    perimetr = 5 * a;
}


void Octagon::setParameters(const double side, const int k)
{
    dify = points[0].y() - centerPoint.y();
    difx = points[0].x() - centerPoint.x();
    double angle = qAtan(dify/difx);
    for(int i = 0; i < pointsCount; i++)
    {
        points[i] = {side * qCos(angle) + centerPoint.x(), side * qSin(angle) + centerPoint.y()};
        angle += (2 * PI / pointsCount);
    }
    updateData();
}
