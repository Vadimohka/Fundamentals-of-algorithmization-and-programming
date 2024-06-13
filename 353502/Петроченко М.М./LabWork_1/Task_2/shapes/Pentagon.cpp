//
// Created by acryoz on 18.2.24.
//

#include "../headers/Pentagon.h"


Pentagon::Pentagon() {
    double radius = 50;
    double q = 100;
    double c1 = std::cos(2 * M_PI/5);
    double c2 = std::cos(M_PI/5);
    double s1 = std::sin(2 * M_PI/5);
    double s2 = std::sin(4 * M_PI/5);
    this->addPoint(QPointF{100 + q * 0,  100 + q * 1});
    this->addPoint(QPointF{100 + q * s1, 100 + q * c1});
    this->addPoint(QPointF{100 + q * s2, 100 + q * -c2});
    this->addPoint(QPointF{100 + q * -s2,100 + q * -c2});
    this->addPoint(QPointF{100 + q * -s1,100 + q * c1});
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
}