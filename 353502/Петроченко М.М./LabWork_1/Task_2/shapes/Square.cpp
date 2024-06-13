//
// Created by acryoz on 18.2.24.
//

#include "../headers/Square.h"


Square::Square() {
    this->addPoint(QPointF{100, 100});
    this->addPoint(QPointF{200, 100});
    this->addPoint(QPointF{200, 200});
    this->addPoint(QPointF{100, 200});
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
}