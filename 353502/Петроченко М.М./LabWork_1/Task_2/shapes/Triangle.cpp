//
// Created by acryoz on 14.2.24.
//

#include "../headers/Triangle.h"


Triangle::Triangle() {
    this->addPoint(QPointF{100, 100});
    this->addPoint(QPointF{200, 70});
    this->addPoint(QPointF{60, 120});
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
    this->figure_id = 1;
}