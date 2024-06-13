//
// Created by acryoz on 18.2.24.
//

#include "../headers/Rhombus.h"


Rhombus::Rhombus() {
    double len = 100;
    this->addPoint(QPointF{100, 100});
    this->addPoint(QPointF{100 + std::sqrt(3)*len/2, 100 - len/2});
    this->addPoint(QPointF{100 + std::sqrt(3)*len/2 + len, 100 - len/2});
    this->addPoint(QPointF{100 + len, 100});
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
}