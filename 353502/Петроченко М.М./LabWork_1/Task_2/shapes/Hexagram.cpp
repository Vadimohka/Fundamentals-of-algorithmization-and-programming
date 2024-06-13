//
// Created by acryoz on 18.2.24.
//

#include "../headers/Hexagram.h"


Hexagram::Hexagram() {
    double radius = 50;
    double side = radius/(2 * std::cos(M_PI/6));
    double a = radius * std::cos(M_PI/3);
    double b = radius * std::sin(M_PI/3);

    this->addPoint(QPointF{100, 200});
    this->addPoint(QPointF{100 + radius/2 - radius, 200 - radius*std::sqrt(3)/2});
    this->addPoint(QPointF{100 + radius/2, 200 - radius*std::sqrt(3)/2});
    this->addPoint(QPointF{100 + radius/2 + a, 200 - radius*std::sqrt(3)/2 - b});
    this->addPoint(QPointF{100 + 3 * radius/2, 200 - radius*std::sqrt(3)/2});
    this->addPoint(QPointF{100 + 3 * radius/2 + radius, 200 - radius*std::sqrt(3)/2});
    this->addPoint(QPointF{200, 200});
    this->addPoint(QPointF{100 + 3 * radius/2 + radius, 200 + radius*std::sqrt(3)/2});
    this->addPoint(QPointF{100 + 3 * radius/2, 200 + radius*std::sqrt(3)/2});
    this->addPoint(QPointF{100 + 3 * radius/2 - a, 200 + radius*std::sqrt(3)/2 + b});
    this->addPoint(QPointF{100 + radius/2, 200 + radius*std::sqrt(3)/2});
    this->addPoint(QPointF{100 + radius/2 - radius, 200 + radius*std::sqrt(3)/2});
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
}
