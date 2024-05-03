#include "../../Headers/BernoulliLemniscate.h"


BernoulliLemniscate::BernoulliLemniscate(QWidget *parent) : Figure(parent, std::vector<QPointF>()) {
    this->setParent(parent);

    this->_radiusC = 0;

    this->points.clear();
}

void BernoulliLemniscate::draw(QPainter *painter) {

    QPen *pen = new QPen;
    pen->setBrush(Qt::black);
    pen->setWidth(3);
    painter->setPen(*pen);

    painter->drawPolygon(_polygon);

    if (true) {
        painter->setPen(Qt::red);
        painter->setBrush(Qt::red);

        painter->drawEllipse(this->_center->x() - 2,
                             this->_center->y() - 2,
                             4,
                             4);
    }
    painter->setPen(Qt::black);

    painter->setBrush(Qt::NoBrush);
}


void BernoulliLemniscate::drawMove(QMouseEvent *event) {
    points.clear();

    this->_center->setX(_insertionPoint.x() + -(_insertionPoint.x() - event->x()) / 2);

    this->_center->setY(_insertionPoint.y() + -(_insertionPoint.y() - event->y()) / 2);

    this->_radiusC = qAbs(_center->x() - event->x());

    for (int i = 0; i <= 2000; i += 25) {
        long double newX =
                _center->x() + (M_SQRT1_2 * (_radiusC) * qCos(M_PI * i / 1000)) / (1 + qPow(qSin(M_PI * i / 1000), 2));

        long double newY = _center->y() + (M_SQRT1_2 * (_radiusC) * qCos(M_PI * i / 1000) * qSin(M_PI * i / 1000)) /
                                          (1 + qPow(qSin(M_PI * i / 1000), 2));

        points.emplace_back(newX, newY);
    }

    _polygon.clear();

    for (int i = 0; i < points.size(); i++) {
        _polygon << points[i];
    }

    findPerimeter();

    findArea();

    update();
}


void BernoulliLemniscate::drawPress(QMouseEvent *event) {
    this->_insertionPoint.setX(event->x());

    this->_insertionPoint.setY(event->y());
}


void BernoulliLemniscate::findArea() {
    this->_area = M_SQRT1_2 * qAbs(_insertionPoint.x() - _center->x()) * qAbs(_insertionPoint.x() - _center->x());
}


void BernoulliLemniscate::findPerimeter() {
    this->_perimeter = 5.244 * qAbs(_insertionPoint.x() - _center->x());
}
