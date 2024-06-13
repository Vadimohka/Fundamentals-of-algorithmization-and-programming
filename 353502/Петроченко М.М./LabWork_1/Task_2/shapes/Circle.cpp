//
// Created by acryoz on 18.2.24.
//

#include "../headers/Circle.h"

Circle::Circle() {
    this->centre = QPointF{100, 100};
    this->radius = 50;

    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
}

void Circle::move() {
    this->centre += this->cur_mouse - this->pressing_mouse;
    this->pressing_mouse = this->cur_mouse;
    emit this->changed();
}

void Circle::resize(int new_scale) {
    double scaling_factor = (double)(new_scale)/5;
    this->radius = (double)this->radius/this->scale * scaling_factor;
    this->scale = scaling_factor;
    emit this->changed();
}

void Circle::draw(QPainter* qPainter) {
    this->area = this->calculateArea();
    this->perimeter = this->calculatePerimeter();
    qPainter->drawEllipse(this->centre, this->radius, this->radius);
    emit this->changed();
}

double Circle::calculatePerimeter() {
    return 2 * M_PI * this->radius;
}

double Circle::calculateArea() {
    return M_PI * this->radius * this->radius;
}

void Circle::rotate(int) {

}


QPointF Circle::findCentre() {
    return this->centre;
}


void Circle::addPoint(QPointF point) {
}