#include "star6.h"


Star6::Star6()
{
    flag = 8;
}


void Star6::setPoints(QMouseEvent* event)
{
    nowPosition = event->pos();
    pointsCount = 12;
    centerPoint = {(pressPosition.x() + nowPosition.x()) / 2, pressPosition.y() + (nowPosition.x() - pressPosition.x()) / 2};
    points[0] = {(pressPosition.x() + nowPosition.x()) / 2, pressPosition.y()};
    double angle = PI / 3;
    for(int i = 2; i <= 10; i += 2)
    {
        points[i] = rotatePoint(centerPoint, points[0], angle);
        angle += PI/3;
    }
    QPointF buf = {(pressPosition.x() + nowPosition.x()) / 2,
                   (centerPoint.y() + 0.6 * points[0].y()) / 1.6};
    points[1] = rotatePoint(centerPoint, buf, PI / 6);
    angle = PI / 3;
    for(int i = 3; i <= 11; i += 2)
    {
        points[i] = rotatePoint(centerPoint, points[1], angle);
        angle += PI/3;
    }
    updateData();
}


void Star6::updateData()
{
    double a = distance(points[1], points[11]);
    double b = distance(points[0], centerPoint);
    double side = distance(points[1], points[0]);
    square = 3 * a * b;
    perimetr = side * 12;

}


void Star6::setParameters(const double radius, const int k)
{
    double dist, angle;
    if(k == 1)
    {
        dist = distance(centerPoint, points[1]);
        if(radius > dist)
        {
            points[1] = (points[1] * radius - centerPoint * (radius - dist)) / dist;
            angle = PI / 3;
            for(int i = 3; i <= 11; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[1], angle);
                angle += (PI / 3);
            }
        }
        else if(radius < dist)
        {
            points[1] = (centerPoint + (radius / (dist - radius)) * points[1]) / (1 + radius / (dist - radius));
            angle = PI / 3;
            for(int i = 3; i <= 11; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[1], angle);
                angle += (PI / 3);
            }
        }
    }
    else if(k == 2)
    {
        dist = distance(centerPoint, points[0]);
        if(radius > dist)
        {
            points[0] = (points[0] * radius - centerPoint * (radius - dist)) / dist;
            angle = PI / 3;
            for(int i = 2; i <= 10; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[0], angle);
                angle += (PI / 3);
            }
        }
        else if(radius < dist)
        {
            points[0] = (centerPoint + (radius / (dist - radius)) * points[0]) / (1 + radius / (dist - radius));
            angle = PI / 3;
            for(int i = 2; i <= 10; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[0], angle);
                angle += (PI / 3);
            }
        }
    }
}
