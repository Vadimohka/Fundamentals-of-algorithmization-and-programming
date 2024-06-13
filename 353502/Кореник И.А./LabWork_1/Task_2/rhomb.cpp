#include "rhomb.h"

Rhomb::Rhomb(QWidget* parent)
    : Figure(parent) {
    this->setParent(parent);
    points.clear();
    points.resize(4);
}


void Rhomb::setPoints(){
    points = {
        {(static_cast<double>(mousePress.x()) + mouseNow.x()) / 2, static_cast<double>(mousePress.y())},
        {(static_cast<double>(mouseNow.x())), (static_cast<double>(mouseNow.y()) + mousePress.y()) / 2},
        {(static_cast<double>(mousePress.x()) + mouseNow.x()) / 2, static_cast<double>(mouseNow.y())},
        {(static_cast<double>(mousePress.x())), (static_cast<double>(mouseNow.y()) + mousePress.y()) / 2},
    };
}


void Rhomb::calcArea(){
    area = abs((points[2].y() - points[0].y()) * (points[3].x() - points[1].x()) / 2);
}


void Rhomb::calcPerimetr(){
    perimetr = 4 * sqrt(pow(points[0].x() - points[1].x(), 2) + pow(points[0].y() - points[1].y(), 2));
}


void Rhomb::calcCentre(){
    centre = (points[0] + points[3]) / 2;
}
