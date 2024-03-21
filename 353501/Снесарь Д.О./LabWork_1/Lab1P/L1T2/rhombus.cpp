#include "rhombus.h"

Rhombus::Rhombus(QPointF first, QPointF second)
{
    center = first;
    points.push_back(QPointF(first.x() + second.x(),first.y()));
    points.push_back(QPointF(first.x(),first.y() + second.y()));
    points.push_back(QPointF(first.x() - second.x(),first.y()));
    points.push_back(QPointF(first.x(),first.y() - second.y()));
}

void Rhombus::setSize(QPointF nPoint)
{
    points[0] = (QPointF(center.x() + nPoint.x(),center.y()));
    points[1] = (QPointF(center.x(),center.y() + nPoint.y()));
    points[2] = (QPointF(center.x() - nPoint.x(),center.y()));
    points[3] = (QPointF(center.x(),center.y() - nPoint.y()));
}
