#include "../../Headers/Star.h"


Star::Star(QWidget *parent) : Figure(parent, std::vector<QPointF>()) {
    this->setParent(parent);

    this->_radiusS = 0;

    this->_xRadiusB = 0;

    this->_yRadiusB = 0;

    this->_thorns = 7;

    this->points.emplace_back();
}


void Star::draw(QPainter *painter) {

    QPen *pen = new QPen;
    pen->setBrush(Qt::black);
    pen->setWidth(3);
    painter->setPen(*pen);

    painter->drawPolygon(_polygon);

    if (this->_radiusS != 0 || this->_xRadiusB != 0) {
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


void Star::drawMove(QMouseEvent *event) {
    this->_xRadiusB = (int) (event->x() - this->_insertionPoint.x()) / 2;
    this->_yRadiusB = (int) (event->y() - this->_insertionPoint.y()) / 2;

    int signX = _xRadiusB < 0 ? -1 : 1;
    this->_xRadiusB = signX * qMin(qAbs(_xRadiusB), qAbs(_yRadiusB));

    int signY = _yRadiusB < 0 ? -1 : 1;
    this->_yRadiusB = signY * qMin(qAbs(_xRadiusB), qAbs(_yRadiusB));

    this->_radiusS = this->_xRadiusB / M_PI;

    this->_center->setX(this->_insertionPoint.x() + this->_xRadiusB);

    this->_center->setY(this->_insertionPoint.y() + this->_yRadiusB);

    //double height = qSqrt(-qPow(_xRadius, 2) / 4 + qPow(_yRadius,2));

    setStar(_thorns, event->x(), event->y());

    findPerimeter();

    findArea();

    update();
}

void Star::setStar(int thorns, int eventX, int eventY) {
    points.clear();
    points.emplace_back(_center->x(), _center->y() - _xRadiusB);

    float smallX = _center->x();
    float smallY = _center->y() - _radiusS;

    long double newX = (smallX - _center->x()) * qCos(M_PI / thorns) + (smallY - _center->y()) * qSin(M_PI / thorns) +
                       _center->x();
    long double newY = (smallY - _center->y()) * qCos(M_PI / thorns) - (smallX - _center->x()) * qSin(M_PI / thorns) +
                       _center->y();

    points.emplace_back(newX, newY);

    for (int i = 0; i < thorns - 1; i++) {
        newX = (points[i * 2].x() - _center->x()) * qCos(M_PI / thorns * 2) +
               (points[i * 2].y() - _center->y()) * qSin(M_PI / thorns * 2) + _center->x();
        newY = (points[i * 2].y() - _center->y()) * qCos(M_PI / thorns * 2) -
               (points[i * 2].x() - _center->x()) * qSin(M_PI / thorns * 2) + _center->y();
        points.emplace_back(newX, newY);
        newX = (points[i * 2 + 1].x() - _center->x()) * qCos(M_PI / thorns * 2) +
               (points[i * 2 + 1].y() - _center->y()) * qSin(M_PI / thorns * 2) + _center->x();
        newY = (points[i * 2 + 1].y() - _center->y()) * qCos(M_PI / thorns * 2) -
               (points[i * 2 + 1].x() - _center->x()) * qSin(M_PI / thorns * 2) + _center->y();
        points.emplace_back(newX, newY);
    }

    this->_polygon.clear();

    for (int i = 0; i < points.size(); i++) { this->_polygon << points[i]; }
}


void Star::findArea() {
    long double side = qSqrt(qPow(points[1].x() - points[3].x(), 2) + qPow(points[1].y() - points[3].y(), 2));
    this->_area = _thorns * (qAbs(side * _radiusS) + qAbs(side * (_xRadiusB - _radiusS))) / 4;
}


void Star::findPerimeter() {
    this->_perimeter =
            2 * _thorns * qSqrt(qPow(points[0].x() - points[1].x(), 2) + qPow(points[0].y() - points[1].y(), 2));
}