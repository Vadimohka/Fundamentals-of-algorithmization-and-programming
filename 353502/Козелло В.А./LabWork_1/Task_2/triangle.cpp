#include "triangle.h"

Triangle::Triangle()
{
    pointsCount = 0;
    flag = 6;
}


void Triangle::setPoints(QMouseEvent* event)
{
    if(pointsCount < 3)
    {
        pressPosition = event->pos();
        points[pointsCount] = pressPosition;
        pointsCount++;
    }
    if(pointsCount == 3)
    {
        centerPoint = {(points[0].x() + points[1].x() + points[2].x()) / 3, (points[0].y() + points[1].y() + points[2].y()) / 3};
    }
}


void Triangle::mousePress(QMouseEvent* event)
{
    pressPosition = event->pos();
    nowPosition = event->pos();
    setPoints(event);
    if(pointsCount == 3 && pointsFlag == false)
    {
        updateData();
        pointsFlag = true;
    }
}


void Triangle::updateData()
{
    if(pointsCount == 3)
    {
        double x1 = points[0].x();
        double x2 = points[1].x();
        double x3 = points[2].x();
        double y1 = points[0].y();
        double y2 = points[1].y();
        double y3 = points[2].y();
        square = 0.5 * qFabs((x2 - x3) * (y3 - y1) - (x3 - x1) * (y2 - y1));
        perimetr = distance(points[0], points[1]) + distance(points[1], points[2]) + distance(points[2], points[0]);
        centerPoint = {(points[0].x() + points[1].x() + points[2].x()) / 3, (points[0].y() + points[1].y() + points[2].y()) / 3};
    }
    else
    {
        square = 0;
        perimetr = 0;
    }
}


void Triangle::setNewPoints(double point, int num)
{
    switch(num)
    {
        case 1:
            points[0] = {point, points[0].y()};
            break;
        case 2:
            points[0] = {points[0].x(), point};
            break;
        case 3:
            points[1] = {point, points[1].y()};
            break;
        case 4:
            points[1] = {points[1].x(), point};
            break;
        case 5:
            points[2] = {point, points[2].y()};
            break;
        case 6:
            points[2] = {points[2].x(), point};
            break;
    }
    updateData();
}
