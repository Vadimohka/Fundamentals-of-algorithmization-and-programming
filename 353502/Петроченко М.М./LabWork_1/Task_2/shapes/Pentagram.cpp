//
// Created by acryoz on 18.2.24.
//

#include "../headers/Pentagram.h"


Pentagram::Pentagram() {
    double inner_radius = 45;
    double outer_radius = 125;
    this->addPoint(QPointF{100 + outer_radius*std::cos(162 * M_PI/180), 100 + outer_radius*std::sin(162 *M_PI/180)});
    this->addPoint(QPointF{100 + inner_radius*std::cos(126 * M_PI/180), 100 + inner_radius*std::sin(126 * M_PI/180)});
    this->addPoint(QPointF{100 + outer_radius*std::cos(90 * M_PI/180), 100 + outer_radius*std::sin(90 *M_PI/180)});
    this->addPoint(QPointF{100 + inner_radius*std::cos(53 * M_PI/180), 100 + inner_radius*std::sin(53 * M_PI/180)});
    this->addPoint(QPointF{100 + outer_radius*std::cos(18 * M_PI/180), 100 + outer_radius*std::sin(18 *M_PI/180)});
    this->addPoint(QPointF{100 + inner_radius*std::cos(342 * M_PI/180), 100 + inner_radius*std::sin(342 * M_PI/180)});
    this->addPoint(QPointF{100 + outer_radius*std::cos(306 * M_PI/180), 100 + outer_radius*std::sin(306 *M_PI/180)});
    this->addPoint(QPointF{100 + inner_radius*std::cos(270 * M_PI/180), 100 + inner_radius*std::sin(270 * M_PI/180)});
    this->addPoint(QPointF{100 + outer_radius*std::cos(234 * M_PI/180), 100 + outer_radius*std::sin(234 *M_PI/180)});
    this->addPoint(QPointF{100 + inner_radius*std::cos(198 * M_PI/180), 100 + inner_radius*std::sin(198 * M_PI/180)});
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
}