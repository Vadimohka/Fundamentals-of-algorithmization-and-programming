#include "triangle.h"

Triangle::Triangle(QPointF first, QPointF second)
{
    center = first;
    points.push_back(QPointF(center.x(), center.y() - (double)second.y()/sqrt(3)));
    points.push_back(QPointF(center.x() + nPoint.x()/2, this->center.y() + (double)second.y()/(2*sqrt(3))));
    points.push_back(QPointF(center.x() - nPoint.x()/2, this->center.y() + (double)second.y()/(2*sqrt(3))));

}

void Triangle::setSize(QPointF nPoint)
{
    points[0] = QPointF(center.x(), center.y() - (double)nPoint.y()/sqrt(3));
    points[1] = QPointF(center.x() + nPoint.x()/2, this->center.y() + (double)nPoint.y()/(2*sqrt(3)));
    points[2] = QPointF(center.x() - nPoint.x()/2, this->center.y() + (double)nPoint.y()/(2*sqrt(3)));


}
