#include "../../Headers/Triangle.h"

Triangle::Triangle(QWidget *parent) : Figure(parent, std::vector<QPointF>()) {
    this->setParent(parent);

    points.emplace_back(0, 0);
    points.emplace_back(0, 0);
    points.emplace_back(0, 0);
    points.emplace_back(0, 0);
}


void Triangle::draw(QPainter *painter) {

    if (points.size() == 3) {
        QPen *pen = new QPen;
        pen->setBrush(Qt::black);
        pen->setWidth(3);
        painter->setPen(*pen);

        painter->drawPolygon(_polygon);

        painter->setPen(Qt::black);
        painter->setBrush(Qt::black);


        if (_perimeter != 0) {
            painter->drawEllipse(this->_center->x() - 2,
                                 this->_center->y() - 2,
                                 4,
                                 4);
        }
        painter->setPen(Qt::black);

        painter->setBrush(Qt::NoBrush);
    }
}


void Triangle::drawPress(QMouseEvent *event) {

    if (points.size() == 4) {
        points.clear();
    }
    if (points.size() < 2) {
        points.emplace_back(event->pos());
    } else if (points.size() != 3) {
        points.emplace_back(event->pos());

        _polygon.clear();

        _polygon << points[0] << points[1] << points[2];

        this->_center->setX((points[0].x() + points[1].x() + points[2].x()) / 3);
        this->_center->setY((points[0].y() + points[1].y() + points[2].y()) / 3);

        findArea();

        update();
    }
}


void Triangle::drawMove(QMouseEvent *event) {
    findArea();
}


void Triangle::findArea() {
    this->findPerimeter();
    double halfPerimeter = _perimeter / 2;
    this->_area = qSqrt(halfPerimeter *
                        (halfPerimeter -
                         qSqrt(qPow(points[0].x() - points[1].x(), 2) + qPow(points[0].y() - points[1].y(), 2))) *
                        (halfPerimeter -
                         qSqrt(qPow(points[0].x() - points[2].x(), 2) + qPow(points[0].y() - points[2].y(), 2))) *
                        (halfPerimeter -
                         qSqrt(qPow(points[2].x() - points[1].x(), 2) + qPow(points[2].y() - points[1].y(), 2))));
}


void Triangle::findPerimeter() {
    if (points.size() == 3) {
        this->_perimeter = qSqrt(qPow(points[0].x() - points[1].x(), 2) + qPow(points[0].y() - points[1].y(), 2)) +
                           qSqrt(qPow(points[0].x() - points[2].x(), 2) + qPow(points[0].y() - points[2].y(), 2)) +
                           qSqrt(qPow(points[2].x() - points[1].x(), 2) + qPow(points[2].y() - points[1].y(), 2));
    }
}