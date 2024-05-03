#include "rectangle.h"

Rectangle::Rectangle()
{
    flag = 2;
}


void Rectangle::setPoints(QMouseEvent* event)
{
    nowPosition = event->pos();
    pointsCount = 4;
    points[0] = pressPosition;
    points[1] = {nowPosition.x(), pressPosition.y()};
    points[2] = nowPosition;
    points[3] = {pressPosition.x(), nowPosition.y()};
    centerPoint = {(pressPosition.x() + nowPosition.x())/2, (pressPosition.y() + nowPosition.y())/2};
    updateData();
}


void Rectangle::updateData()
{
    double a = qSqrt((points[0].x() - points[1].x()) * (points[0].x() - points[1].x()) +
                     (points[0].y() - points[1].y()) * (points[0].y() - points[1].y()));
    double b = qSqrt((points[2].x() - points[1].x()) * (points[2].x() - points[1].x()) +
                     (points[2].y() - points[1].y()) * (points[2].y() - points[1].y()));
    square = a * b;
    perimetr = 2 * (a + b);
}


void Rectangle::setParameters(const double side, const int k)
{
    if(k == 1)
    {
        points[1] = {points[0].x() + side * qCos(nowAngle),
                     points[0].y() + side * qSin(nowAngle)};
        points[2] = {points[3].x() + side * qCos(nowAngle),
                     points[3].y() + side * qSin(nowAngle)};
    }
    else if(k == 2)
    {
        points[2] = {points[1].x() + side * qSin(-nowAngle),
                     points[1].y() + side * qCos(-nowAngle)};
        points[3] = {points[0].x() + side * qSin(-nowAngle),
                     points[0].y() + side * qCos(-nowAngle)};
    }
    centerPoint = {(points[0].x() + points[2].x()) / 2, (points[0].y() + points[2].y()) / 2};
    updateData();
}
