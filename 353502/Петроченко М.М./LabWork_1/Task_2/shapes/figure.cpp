//
// Created by acryoz on 14.2.24.
//

#include "../headers/figure.h"

figure::figure() {}


void figure::move() {
    QPointF distance = this->cur_mouse - this->pressing_mouse;
    for(auto &point: this->vertices){
        point += distance;
    }
    this->centre += distance;
    this->pressing_mouse = this->cur_mouse;
    emit this->changed();
}

void figure::resize(int new_scale) {
    double scaling_factor = (double)(new_scale)/5;
    for(auto &point : this->vertices){
        point = this->centre + (point - this->centre)/this->scale * scaling_factor;
    }
    this->scale = scaling_factor;
    emit this->changed();
}

void figure::draw(QPainter *painter) {
    QPolygonF polygon;
    for(auto &v : this->vertices){
        QPointF point(v.x(), v.y());
        polygon << point;
    }
    this->centre = this->findCentre();
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();

    painter->drawPolygon(polygon);
    emit this->changed();
}


double figure::calculatePerimeter() {
    double perimeter;
    for(int i = 0; i < this->vertices.length(); ++i){
        if(i == this->vertices.length() - 1){
            perimeter += std::sqrt(std::pow(this->vertices[i].x() - this->vertices[0].x(), 2) + std::pow(this->vertices[i].y() - this->vertices[0].y(), 2));
        }
        else{
            perimeter += std::sqrt(std::pow(this->vertices[i].x() - this->vertices[i+1].x(), 2) + std::pow(this->vertices[i].y() - this->vertices[i+1].y(), 2));
        }
    }
    return perimeter;
}

double figure::calculateArea() {
    double area;
    for(int i = 0; i < this->vertices.length(); ++i){
        if(i == this->vertices.length() - 1){
            area += this->vertices[i].x() * this->vertices[0].y() - this->vertices[0].x() * this->vertices[i].y();
        }
        else{
            area += this->vertices[i].x() * this->vertices[i+1].y() - this->vertices[i+1].x() * this->vertices[i].y();
        }
    }
    area /= 2;
    return area;
}


void figure::rotate(int new_angle) {
    this->centre = this->findCentre();
    double delta_angle = (this->angle - new_angle)/180 * M_PI;
    for (auto &v: this->vertices) {
        double qx = this->centre.x() + std::cos(delta_angle) * (v.x() - this->centre.x()) - std::sin(delta_angle) * (v.y() - this->centre.y());
        double qy = this->centre.y() + std::sin(delta_angle) * (v.x() - this->centre.x()) + std::cos(delta_angle) * (v.y() - this->centre.y());
        v = {qx, qy};
    }
    this->angle = new_angle;
    emit this->changed();
}


QPointF figure::findCentre() {
    if(this->vertices.size() == 3){
        return (this->vertices[0] + this->vertices[1] + this->vertices[2])/3;
    }
    else{
        double xp = this->vertices[0].x(), xm = this->vertices[0].x(), yp = this->vertices[0].y(), ym = this->vertices[0].y();
        for (auto &vertice : this->vertices) {
            xp = qMin(vertice.x(), xp);
            xm = qMax(vertice.x(), xm);
            yp = qMin(vertice.y(), yp);
            ym = qMax(vertice.y(), ym);
        }
        return QPointF{(xp + xm) / 2, (yp + ym) / 2};
    }
}


void figure::addPoint(QPointF point) {
    this->vertices.push_back(point);
    this->area = std::abs(this->calculateArea());
    this->perimeter = this->calculatePerimeter();
    this->centre = this->findCentre();
    emit this->changed();
}



void figure::mousePress(QMouseEvent *mouseEvent) {
    this->pressing_mouse= mouseEvent->pos();
}


void figure::mouseMove(QMouseEvent *mouseEvent) {
    this->cur_mouse = mouseEvent->pos();
    this->move();
}


void figure::mouseRelease(QMouseEvent *mouseEvent) {
    this->released_mouse = mouseEvent->pos();
}


double figure::getScale() {
    return this->scale;
}


double figure::getPerimeter() {
    return this->perimeter;
}


double figure::getAngle(){
    return this->angle;
}


double figure::getArea(){
    return this->area;
}


QPointF figure::getCentre() {
    return this->centre;
}


void figure::setV1x(QString new_x) {
    if(this->figure_id == 1 || this->figure_id == 2){
        this->vertices[0].setX(new_x.toDouble());
    }
}


void figure::setV1y(QString new_y) {
    if(this->figure_id == 1 || this->figure_id == 2){
        this->vertices[0].setY(new_y.toDouble());
    }
}


void figure::setV2x(QString new_x) {
    if(this->figure_id == 1 || this->figure_id == 2){
        this->vertices[1].setX(new_x.toDouble());
    }
}


void figure::setV2y(QString new_y) {
    if(this->figure_id == 1 || this->figure_id == 2){
        this->vertices[1].setY(new_y.toDouble());
    }
}


void figure::setV3x(QString new_x) {
    if(this->figure_id == 1 || this->figure_id == 2){
        this->vertices[2].setX(new_x.toDouble());
    }
}


void figure::setV3y(QString new_y) {
    if(this->figure_id == 1 || this->figure_id == 2){
        this->vertices[2].setY(new_y.toDouble());
    }
}


void figure::setV4x(QString new_x) {
    if(this->figure_id == 2){
        this->vertices[3].setX(new_x.toDouble());
    }
}


void figure::setV4y(QString new_y) {
    if(this->figure_id == 2){
        this->vertices[3].setY(new_y.toDouble());
    }
}
