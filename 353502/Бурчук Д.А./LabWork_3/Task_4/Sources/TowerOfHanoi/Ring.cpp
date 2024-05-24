#include "../../Headers/Ring.h"

Ring::Ring() {
    _pos = 1;
}

void Ring::setWidth(float width) {
    this->_width = width;
}

void Ring::setHeight(float height) {
    this->_height = height;
}

float Ring::width() const {
    return _width;
}

float Ring::height() const {
    return _height;
}

void Ring::setPoint(QPointF point) {
    _center = point;
    this->setRing(this->_center.x() - width(), this->_center.y() - height(), width() * 2, height() * 2);
}

void Ring::setPos(uint pos) {
    _pos = pos;
}

int Ring::pos() {
    return _pos;
}

QPointF Ring::center() {
    return _center;
}

float Ring::x() {
    return _center.x();
}

float Ring::y() {
    return _center.y();
}

QRectF Ring::ring() {
    return _ring;
}

void Ring::setRing(float xPos, float yPos, float width, float height) {
    _ring = QRectF(xPos, yPos, width, height);
}