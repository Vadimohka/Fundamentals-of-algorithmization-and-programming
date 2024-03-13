#include "star5.h"

Star5::Star5()
{
    flag = 7;
}


void Star5::setPoints(QMouseEvent* event)
{
    nowPosition = event->pos();
    pointsCount = 10;
    centerPoint = {(pressPosition.x() + nowPosition.x()) / 2, pressPosition.y() + (nowPosition.x() - pressPosition.x()) / 2};
    points[0] = {(pressPosition.x() + nowPosition.x()) / 2, pressPosition.y()};
    double angle = 0.4 * PI;
    for(int i = 2; i <= 8; i += 2)
    {
        points[i] = rotatePoint(centerPoint, points[0], angle);
        angle += (0.4 * PI);
    }
    QPointF buf = {(pressPosition.x() + nowPosition.x()) / 2,
                   (centerPoint.y() + 0.6 * points[0].y()) / 1.6};
    points[1] = rotatePoint(centerPoint, buf, 0.2 * PI);
    angle = 0.4 * PI;
    for(int i = 3; i <= 9; i += 2)
    {
        points[i] = rotatePoint(centerPoint, points[1], angle);
        angle += (0.4 * PI);
    }
    updateData();
}


void Star5::updateData()
{
    double a = distance(points[1], points[9]);
    double b = distance(points[0], centerPoint);
    double side = distance(points[1], points[0]);
    square = 2.5 * a * b;
    perimetr = side * 10;
}


void Star5::setParameters(const double radius, const int k)
{
    double dist, angle;
    if(k == 1)
    {
        dist = distance(centerPoint, points[1]);
        if(radius > dist)
        {
            points[1] = (points[1] * radius - centerPoint * (radius - dist)) / dist;
            angle = 0.4 * PI;
            for(int i = 3; i <= 9; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[1], angle);
                angle += (0.4 * PI);
            }
        }
        else if(radius < dist)
        {
            points[1] = (centerPoint + (radius / (dist - radius)) * points[1]) / (1 + radius / (dist - radius));
            angle = 0.4 * PI;
            for(int i = 3; i <= 9; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[1], angle);
                angle += (0.4 * PI);
            }
        }
    }
    else if(k == 2)
    {
        dist = distance(centerPoint, points[0]);
        if(radius > dist)
        {
            points[0] = (points[0] * radius - centerPoint * (radius - dist)) / dist;
            angle = 0.4 * PI;
            for(int i = 2; i <= 8; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[0], angle);
                angle += (0.4 * PI);
            }
        }
        else if(radius < dist)
        {
            points[0] = (centerPoint + (radius / (dist - radius)) * points[0]) / (1 + radius / (dist - radius));
            angle = 0.4 * PI;
            for(int i = 2; i <= 8; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[0], angle);
                angle += (0.4 * PI);
            }
        }
    }
}
