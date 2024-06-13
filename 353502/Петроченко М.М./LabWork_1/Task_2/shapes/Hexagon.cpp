//
// Created by acryoz on 18.2.24.
//

#include "../headers/Hexagon.h"

Hexagon::Hexagon(){
    double radius = 50;
    this->addPoint(QPointF{100, 200});
    this->addPoint(QPointF{100 + radius/2, 200 - radius*std::sqrt(3)/2});
    this->addPoint(QPointF{100 + 3 * radius/2, 200 - radius*std::sqrt(3)/2});
    this->addPoint(QPointF{200, 200});
    this->addPoint(QPointF{100 + 3 * radius/2, 200 + radius*std::sqrt(3)/2});
    this->addPoint(QPointF{100 + radius/2, 200 + radius*std::sqrt(3)/2});
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
}