#include "rectangle.h"

Rectangle::Rectangle(QWidget *parent)
    : Figure(parent)
{
    this->setParent(parent);

    points.clear();
}


void Rectangle::setPoints(){
    Figure::points.resize(4);

    points = {
        {static_cast<double>(mousePress.x()), static_cast<double>(mousePress.y())},
        {static_cast<double>(mousePress.x()), static_cast<double>(mouseNow.y())},
        {static_cast<double>(mouseNow.x()), static_cast<double>(mouseNow.y())},
        {static_cast<double>(mouseNow.x()), static_cast<double>(mousePress.y())},
    };
    calcCentre();
}

void Rectangle::calcCentre(){
    centre.setX((static_cast<double>(points[0].x() + points[2].x()) / 2));
    centre.setY((static_cast<double>(points[0].y() + points[2].y()) / 2));
}


void Rectangle::calcArea(){
    float a = sqrt(pow(points[0].x() - points[3].x(), 2) + pow(points[0].y() - points[3].y(), 2));
    float b = sqrt(pow(points[0].x() - points[1].x(), 2) + pow(points[0].y() - points[1].y(), 2));
    area = a * b;
}

void Rectangle::calcPerimetr(){
    float a = sqrt(pow(points[0].x() - points[3].x(), 2) + pow(points[0].y() - points[3].y(), 2));
    float b = sqrt(pow(points[0].x() - points[1].x(), 2) + pow(points[0].y() - points[1].y(), 2));
    perimetr = 2 * (a + b);
}
