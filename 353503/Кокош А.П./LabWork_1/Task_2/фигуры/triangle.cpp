#include "triangle.h"

enum { NUM_OF_POINTS = 3 };

void triangle::setPoints(QMouseEvent *event)
{
    if (points.size() == NUM_OF_POINTS)
        points.clear();

    mouseCurrentPos = event->pos();

    points.push_back(mouseCurrentPos);

    if (points.size() == NUM_OF_POINTS) {
        center = {(points[0] + points[1] + points[2]) / NUM_OF_POINTS};
    }
}
