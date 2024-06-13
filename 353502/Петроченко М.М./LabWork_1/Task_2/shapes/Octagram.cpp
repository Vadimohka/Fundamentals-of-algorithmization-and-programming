//
// Created by acryoz on 18.2.24.
//

#include "../headers/Octagram.h"


Octagram::Octagram() {
    double c = 2;
    this->addPoint(QPointF{c* 70, c * 100});
    this->addPoint(QPointF{c* 50, c * 80});
    this->addPoint(QPointF{c* 80, c * 80});
    this->addPoint(QPointF{c* 80, c * 50});
    this->addPoint(QPointF{c* 100,c * 70});
    this->addPoint(QPointF{c* 120,c * 50});
    this->addPoint(QPointF{c* 120,c * 80});
    this->addPoint(QPointF{c* 150,c * 80});
    this->addPoint(QPointF{c* 130,c * 100});
    this->addPoint(QPointF{c* 150,c * 120});
    this->addPoint(QPointF{c* 120,c * 120});
    this->addPoint(QPointF{c* 120,c * 150});
    this->addPoint(QPointF{c* 100,c * 130});
    this->addPoint(QPointF{c* 100,c * 130});
    this->addPoint(QPointF{c* 80, c * 150});
    this->addPoint(QPointF{c* 80, c * 120});
    this->addPoint(QPointF{c* 50, c * 120});
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
}
