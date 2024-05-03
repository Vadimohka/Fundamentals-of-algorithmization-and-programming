#include "rhomb.h"

Rhomb::Rhomb()
{
    flag = 4;
}


void Rhomb::setPoints(QMouseEvent* event)
{
    nowPosition = event->pos();
    pointsCount = 4;
    points[0] = {(pressPosition.x() + nowPosition.x()) / 2, pressPosition.y()};
    points[1] = {nowPosition.x(), (pressPosition.y() + nowPosition.y()) / 2};
    points[2] = {(pressPosition.x() + nowPosition.x()) / 2, nowPosition.y()};
    points[3] = {pressPosition.x(), (pressPosition.y() + nowPosition.y()) / 2};
    centerPoint = (pressPosition + nowPosition) / 2;
    updateData();
}


void Rhomb::updateData()
{
    double diag1 = qSqrt((points[0].x() - points[2].x()) * (points[0].x() - points[2].x()) +
                         (points[0].y() - points[2].y()) * (points[0].y() - points[2].y()));
    double diag2 = qSqrt((points[1].x() - points[3].x()) * (points[1].x() - points[3].x()) +
                         (points[1].y() - points[3].y()) * (points[1].y() - points[3].y()));
    double a = qSqrt((points[0].x() - points[1].x()) * (points[0].x() - points[1].x()) +
                     (points[0].y() - points[1].y()) * (points[0].y() - points[1].y()));
    square = diag1 * diag2 / 2;
    perimetr = 4 * a;
}


void Rhomb::setParameters(const double par, const int k)
{
    if(k == 2)
    {
        double side = distance(points[0], points[1]);
        double radian = par * PI / 180;
        points[0] = {points[0].x(), centerPoint.y() - side * qCos(radian / 2)};
        points[1] = {centerPoint.x() + side * qSin(radian / 2), points[1].y()};
        points[2] = {points[2].x(), centerPoint.y() + side * qCos(radian / 2)};
        points[3] = {centerPoint.x() - side * qSin(radian / 2), points[3].y()};
    }
    else if (k == 1)
    {
        double side = par;
        double radian = qAtan(distance(points[1], centerPoint) / distance(points[0], centerPoint));
        points[0] = {points[0].x(), centerPoint.y() - side * qCos(radian)};
        points[1] = {centerPoint.x() + side * qSin(radian), points[1].y()};
        points[2] = {points[2].x(), centerPoint.y() + side * qCos(radian)};
        points[3] = {centerPoint.x() - side * qSin(radian), points[3].y()};
    }
    updateData();
}
