#include "triangle.h"

void triangle::setPoints(QMouseEvent *event)
{


    if(points.size() == 3)
        points.clear();

    mouseCurrentPos = event->pos();

    points.push_back(mouseCurrentPos);

    if(points.size() == 3)
    {
        center = {(points[0] + points[1] + points[2]) / 3};
    }
}
