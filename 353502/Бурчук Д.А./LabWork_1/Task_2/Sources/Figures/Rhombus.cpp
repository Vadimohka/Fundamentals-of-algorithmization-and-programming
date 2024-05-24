#include "../../Headers/Rhombus.h"

Rhombus::Rhombus(QWidget *parent) : Figure(parent, std::vector<QPointF>()) {
    this->setParent(parent);

    this->_xRadius = 0;

    this->_yRadius = 0;

    for (int i = 0; i < 4; i++) { points.emplace_back(0, 0); }

}


void Rhombus::draw(QPainter *painter) {

    QPen *pen = new QPen;
    pen->setBrush(Qt::black);
    pen->setWidth(3);
    painter->setPen(*pen);

    painter->drawPolygon(_polygon);

    if (this->_yRadius != 0 || this->_xRadius != 0) {
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


void Rhombus::drawMove(QMouseEvent *event) {
    this->_xRadius = (int) ((event->x() - this->_insertionPoint.x())) / 2;
    this->_yRadius = (int) ((event->y() - this->_insertionPoint.y())) / 2;

    points[0] = QPointF(_insertionPoint.x() + _xRadius, _insertionPoint.y());

    points[1] = QPointF(event->x(), _insertionPoint.y() + _yRadius);

    points[2] = QPointF(_insertionPoint.x() + _xRadius, event->y());

    points[3] = QPointF(_insertionPoint.x(), _insertionPoint.y() + _yRadius);

    this->_polygon.clear();

    this->_polygon << points[0] << points[1] << points[2] << points[3];

    this->_center->setX(this->_insertionPoint.x() + this->_xRadius);

    this->_center->setY(this->_insertionPoint.y() + this->_yRadius);

    findPerimeter();

    findArea();

    update();
}


void Rhombus::findArea() {
    this->_area = qAbs(_xRadius * _yRadius * 2);
}


void Rhombus::findPerimeter() {
    this->_perimeter = 4 * qAbs(qSqrt(qPow(_xRadius, 2) + qPow(_yRadius, 2)));
}
