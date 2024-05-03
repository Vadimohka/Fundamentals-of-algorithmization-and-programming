#include "../../Headers/Hexagon.h"


Hexagon::Hexagon(QWidget *parent) : Figure(parent, std::vector<QPointF>()) {
    this->setParent(parent);

    this->_xRadius = 0;

    this->_yRadius = 0;

    for (int i = 0; i < 6; i++) { points.emplace_back(0, 0); }

}


void Hexagon::draw(QPainter *painter) {

    QPen *pen = new QPen;
    pen->setBrush(Qt::black);
    pen->setWidth(3);
    painter->setPen(*pen);

    painter->drawPolygon(_polygon);

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


void Hexagon::drawMove(QMouseEvent *event) {
    this->_xRadius = (int) ((event->x() - this->_insertionPoint.x())) / 2;
    this->_yRadius = (int) ((event->y() - this->_insertionPoint.y())) / 2;

    this->_center->setX(this->_insertionPoint.x() + this->_xRadius);

    this->_center->setY(this->_insertionPoint.y() + this->_yRadius);

    //double height = qSqrt(-qPow(_xRadius, 2) / 4 + qPow(_yRadius,2));

    points[0] = QPointF(event->x() + (-event->x() + _insertionPoint.x()) * 0.75, _insertionPoint.y());

    points[1] = QPointF(event->x() + (-event->x() + _insertionPoint.x()) * 0.25, _insertionPoint.y());

    points[2] = QPointF(event->x(), _insertionPoint.y() + _yRadius);

    points[3] = QPointF(event->x() + (-event->x() + _insertionPoint.x()) * 0.25, event->y());

    points[4] = QPointF(event->x() + (-event->x() + _insertionPoint.x()) * 0.75, event->y());

    points[5] = QPointF(_insertionPoint.x(), _insertionPoint.y() + _yRadius);

    this->_polygon.clear();

    for (int i = 0; i < points.size(); i++) { this->_polygon << points[i]; }

    findPerimeter();

    findArea();

    update();
}


void Hexagon::findArea() {
    this->_area = qAbs(_yRadius * _xRadius * 3);
}


void Hexagon::findPerimeter() {
    this->_perimeter = qAbs(2 * qAbs(_xRadius) + 4 * qSqrt(qPow(_xRadius, 2) / 4 + qPow(_yRadius, 2)));
}
