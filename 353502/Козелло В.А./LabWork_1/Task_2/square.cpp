#include "square.h"

Square::Square()
{
    flag = 1;
}


void Square::setPoints(QMouseEvent* event) {
    nowPosition = event->pos();
    pointsCount = 4;

    int diff = nowPosition.x() - pressPosition.x();
    if(diff < 0)
        diff = -diff;

    if(pressPosition.y() > nowPosition.y())
        diff = -diff;

    points[0] = pressPosition;
    points[1] = {nowPosition.x(), pressPosition.y()};
    points[2] = {nowPosition.x(), pressPosition.y() + diff};
    points[3] = {pressPosition.x(), pressPosition.y() + diff};
    centerPoint = {(pressPosition.x() + nowPosition.x())/2, (pressPosition.y() + diff/2)};
    updateData();
}


void Square::updateData()
{
    double a = qSqrt((points[0].x() - points[1].x()) * (points[0].x() - points[1].x()) +
                     (points[0].y() - points[1].y()) * (points[0].y() - points[1].y()));
    square = a * a;
    perimetr = 4 * a;
}


void Square::setParameters(const double side, const int k)
{
    points[1] = {points[0].x() + side * qCos(nowAngle),
                 points[0].y() + side * qSin(nowAngle)};
    points[2] = {points[1].x() + side * qSin(-nowAngle),
                 points[1].y() + side * qCos(-nowAngle)};
    points[3] = {points[0].x() + side * qSin(-nowAngle),
                 points[0].y() + side * qCos(-nowAngle)};
    centerPoint = {(points[0].x() + points[2].x()) / 2, (points[0].y() + points[2].y()) / 2};
    updateData();
}
