#include "../../Headers/Line.h"


Line::Line(QWidget *parent) : Figure(parent, std::vector<QPointF>()) {
    this->setParent(parent);

    this->points.emplace_back(QPointF(-1, -1));
}

void Line::draw(QPainter *painter) {

    QPen *pen = new QPen;
    pen->setBrush(Qt::black);
    pen->setWidth(3);
    painter->setPen(*pen);

    for (int i = 1; i < points.size(); i++) {
        painter->drawLine(points[i - 1], points[i]);
    }

    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);

    painter->drawEllipse(this->_center->x() - 2,
                         this->_center->y() - 2,
                         4,
                         4);

    painter->setPen(Qt::black);

    painter->setBrush(Qt::NoBrush);
}


void Line::drawPress(QMouseEvent *event) {
    if (points.size() == 1) {
        points.clear();
        this->points.emplace_back(event->pos());
    }
    this->points.emplace_back(event->pos());

    pushPoint();

    update();
}

void Line::pushPoint() {

    long double newX = 0;

    long double newY = 0;

    for (int i = 0; i < points.size(); i++) {
        newX += points[i].x();
        newY += points[i].y();
    }

    this->_center->setX(newX / points.size());

    this->_center->setY(newY / points.size());
}

void Line::drawMove(QMouseEvent *event) {
    this->points.emplace_back(event->pos());

    pushPoint();

    update();
}

void Line::increasingSize() {
    double t = 1.01;
    if (qAbs(points[0].x() - _center->x()) < 600) {
        for (int i = 0; i < points.size(); i++) {
            long double newX = _center->x() + (points[i].x() - _center->x()) * t;
            long double newY = _center->y() + (points[i].y() - _center->y()) * t;
            points[i].setX(newX);
            points[i].setY(newY);
        }

        this->_polygon.clear();

        for (int i = 0; i < points.size(); i++) { this->_polygon << points[i]; }

        update();
    }
}

void Line::diminishingSize() {
    double t = 0.99;
    if (qAbs(points[0].x() - _center->x()) > 10) { // Условие кал переделать
        for (int i = 0; i < points.size(); i++) {
            long double newX = _center->x() + (points[i].x() - _center->x()) * t;
            long double newY = _center->y() + (points[i].y() - _center->y()) * t;
            points[i].setX(newX);
            points[i].setY(newY);
        }

        this->_polygon.clear();

        for (int i = 0; i < points.size(); i++) { this->_polygon << points[i]; }

        update();
    }
}

void Line::findArea() {

}


void Line::findPerimeter() {

}