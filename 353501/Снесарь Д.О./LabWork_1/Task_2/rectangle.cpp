#include "rectangle.h"


Rectangle::Rectangle(QPointF first, QPointF second)
{
    center = first;
    points.push_back(QPointF(center.x() + second.x()/2, center.y() + second.y()/2));
    points.push_back(QPointF(center.x() - second.x()/2, center.y() + second.y()/2));
    points.push_back(QPointF(center.x() - second.x()/2, center.y() - second.y()/2));
    points.push_back(QPointF(center.x() + second.x()/2, center.y() - second.y()/2));
}

void Rectangle::setSize(QPointF nPoint)
{
    points[0] = QPointF(QPointF(center.x() + nPoint.x()/2, center.y() + nPoint.y()/2));
    points[1] = QPointF(QPointF(center.x() - nPoint.x()/2, center.y() + nPoint.y()/2));
    points[2] = QPointF(QPointF(center.x() - nPoint.x()/2, center.y() - nPoint.y()/2));
    points[3] = QPointF(QPointF(center.x() + nPoint.x()/2, center.y() - nPoint.y()/2));
}
