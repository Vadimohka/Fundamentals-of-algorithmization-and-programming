#include "star8.h"

Star8::Star8()
{
    flag = 9;
}


void Star8::setPoints(QMouseEvent* event)
{
    nowPosition = event->pos();
    pointsCount = 16;
    centerPoint = {(pressPosition.x() + nowPosition.x()) / 2, pressPosition.y() + (nowPosition.x() - pressPosition.x()) / 2};
    points[0] = {(pressPosition.x() + nowPosition.x()) / 2, pressPosition.y()};
    double angle = PI / 4;
    for(int i = 2; i <= 14; i += 2)
    {
        points[i] = rotatePoint(centerPoint, points[0], angle);
        angle += PI / 4;
    }
    QPointF buf = {(pressPosition.x() + nowPosition.x()) / 2,
                   (centerPoint.y() + 0.6 * points[0].y()) / 1.6};
    points[1] = rotatePoint(centerPoint, buf, PI / 8);
    angle = PI / 4;
    for(int i = 3; i <= 15; i += 2)
    {
        points[i] = rotatePoint(centerPoint, points[1], angle);
        angle += PI / 4;
    }
    updateData();
}


void Star8::updateData()
{
    double a = distance(points[1], points[15]);
    double b = distance(points[0], centerPoint);
    double side = distance(points[1], points[0]);
    square = 4 * a * b;
    perimetr = side * 16;

}


void Star8::setParameters(const double radius, const int k)
{
    double dist, angle;
    if(k == 1)
    {
        dist = distance(centerPoint, points[1]);
        if(radius > dist)
        {
            points[1] = (points[1] * radius - centerPoint * (radius - dist)) / dist;
            angle = PI / 4;
            for(int i = 3; i <= 15; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[1], angle);
                angle += (PI / 4);
            }
        }
        else if(radius < dist)
        {
            points[1] = (centerPoint + (radius / (dist - radius)) * points[1]) / (1 + radius / (dist - radius));
            angle = PI / 4;
            for(int i = 3; i <= 15; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[1], angle);
                angle += (PI / 4);
            }
        }
    }
    else if(k == 2)
    {
        dist = distance(centerPoint, points[0]);
        if(radius > dist)
        {
            points[0] = (points[0] * radius - centerPoint * (radius - dist)) / dist;
            angle = PI / 4;
            for(int i = 2; i <= 14; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[0], angle);
                angle += (PI / 4);
            }
        }
        else if(radius < dist)
        {
            points[0] = (centerPoint + (radius / (dist - radius)) * points[0]) / (1 + radius / (dist - radius));
            angle = PI / 4;
            for(int i = 2; i <= 14; i += 2)
            {
                points[i] = rotatePoint(centerPoint, points[0], angle);
                angle += (PI / 4);
            }
        }
    }
}
