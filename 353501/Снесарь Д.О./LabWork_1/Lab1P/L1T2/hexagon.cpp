#include "hexagon.h"

Hexagon::Hexagon(QPointF first, QPointF second)
{
    center = first;
    points.push_back(QPointF(center.x() + nPoint.x(), center.y()));
    points.push_back(QPointF(center.x() + nPoint.x()/2,center.y() + nPoint.x()*sqrt(3)/2));
    points.push_back(QPointF(center.x() - nPoint.x()/2,center.y() + nPoint.x()*sqrt(3)/2));
    points.push_back(QPointF(center.x() - nPoint.x(), center.y()));
    points.push_back(QPointF(center.x() - nPoint.x()/2,center.y() - nPoint.x()*sqrt(3)/2));
    points.push_back(QPointF(center.x() + nPoint.x()/2,center.y() - nPoint.x()*sqrt(3)/2));




}

void Hexagon::setSize(QPointF nPoint)
{
    points[0] = QPointF(center.x() + nPoint.x(), center.y());
    points[1] = QPointF(center.x() + nPoint.x()/2,center.y() + nPoint.x()*sqrt(3)/2);
    points[2] = QPointF(center.x() - nPoint.x()/2,center.y() + nPoint.x()*sqrt(3)/2);
    points[3] = QPointF(center.x() - nPoint.x(), center.y());
    points[4] = QPointF(center.x() - nPoint.x()/2,center.y() - nPoint.x()*sqrt(3)/2);
    points[5] = QPointF(center.x() + nPoint.x()/2,center.y() - nPoint.x()*sqrt(3)/2);
}
