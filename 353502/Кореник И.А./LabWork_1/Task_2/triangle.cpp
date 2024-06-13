#include "triangle.h"

Triangle::Triangle(QWidget *parent)
    : Figure(parent)
{
    this->setParent(parent);
    points.clear();
    points.resize(3);
}


void Triangle::setPoints(){
    points = {
        static_cast<QPointF>(mousePress),
        static_cast<QPointF>(mouseNow),
        {static_cast<double>(2 * mouseNow.x() - mousePress.x()), static_cast<double>(mousePress.y())}
    };
}


void Triangle::calcArea(){
    float h = sqrt(pow(points[1].y() - (points[0].y() + points[2].y()) / 2, 2) + pow(points[1].x() - (points[0].x() + points[2].x()) / 2, 2));
    float a = sqrt(pow(points[2].x() - points[0].x(), 2) + pow(points[2].y() - points[0].y(), 2));
    area = a * h / 2;
}


void Triangle::calcPerimetr(){
    float a = sqrt(pow(points[2].x() - points[0].x(), 2) + pow(points[2].y() - points[0].y(), 2));
    float b = sqrt(pow(points[1].x() - points[0].x(), 2) + pow(points[1].y() - points[0].y(), 2));
    perimetr = a + 2 * b;
}


void Triangle::calcCentre(){
    centre.setX((points[1].x() + points[0].x() + points[2].x()) / 3);
    centre.setY((points[1].y() + points[0].y() + points[2].y()) / 3);
}
