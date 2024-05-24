#include "../../Headers/Circle.h"


Circle::Circle(QWidget *parent) : Figure(parent, std::vector<QPointF>()) {
    this->setParent(parent);

    this->_xRadius = 0;

    this->_yRadius = 0;
}


void Circle::draw(QPainter *painter) {
    QPen *pen = new QPen;
    pen->setBrush(Qt::black);
    pen->setWidth(3);
    painter->setPen(*pen);

    painter->drawEllipse(this->_center->x() - this->_xRadius,
                         this->_center->y() - this->_yRadius,
                         2.0 * this->_xRadius,
                         2.0 * this->_yRadius);

    if (this->_xRadius != 0 || this->_yRadius != 0) {
        painter->setPen(Qt::black);
        painter->setBrush(Qt::black);

        painter->drawEllipse(this->_center->x() - 2,
                             this->_center->y() - 2,
                             4,
                             4);
    }
    painter->setPen(Qt::black);

    painter->setBrush(Qt::NoBrush);
}

void Circle::drawMove(QMouseEvent *event) {
    this->_xRadius = ((event->x() - this->_insertionPoint.x())) / 2;
    this->_yRadius = ((event->y() - this->_insertionPoint.y())) / 2;

    int signX = _xRadius < 0 ? -1 : 1;
    this->_xRadius = signX * qMin(qAbs(_xRadius), qAbs(_yRadius));

    int signY = _yRadius < 0 ? -1 : 1;
    this->_yRadius = signY * qMin(qAbs(_xRadius), qAbs(_yRadius));

    this->_center->setX(this->_insertionPoint.x() + this->_xRadius);

    this->_center->setY(this->_insertionPoint.y() + this->_yRadius);

    update();

    findArea();

    findPerimeter();
}


void Circle::increasingSize() {
    float t = 1.01;

    if (this->_xRadius < 600 || this->_yRadius < 600) {
        this->_xRadius *= t;

        this->_yRadius *= t;

        update();

        findArea();

        findPerimeter();
    }
}


void Circle::diminishingSize() {
    const float t = 0.99;

    if (this->_xRadius > 30 || this->_yRadius > 30) {
        this->_xRadius *= t;

        this->_yRadius *= t;

        update();

        findArea();

        findPerimeter();
    }
}


void Circle::rotateRight() {}


void Circle::rotateLeft() {}


void Circle::findArea() {
    this->_area = qAbs(this->_xRadius * this->_xRadius * M_PI);
}


void Circle::findPerimeter() {
    this->_perimeter = qAbs(this->_xRadius * 2 * M_PI);
}