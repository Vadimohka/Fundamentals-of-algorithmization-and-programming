4#include "star.h"

Star::Star() : Figure()
{}
double Star::distance(QPointF p1, QPointF p2)
{
    return sqrt((p1.x() - p2.x()) * (p1.x() - p2.x()) + (p1.y() - p2.y()) * (p1.y() - p2.y()));
}

