//
// Created by acryoz on 17.2.24.
//

#include "../headers/Rectangle.h"

Rectangle::Rectangle() {
    this->addPoint(QPointF{100, 100});
    this->addPoint(QPointF{100, 300});
    this->addPoint(QPointF{200, 300});
    this->addPoint(QPointF{200, 100});
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
    this->figure_id = 2;
}