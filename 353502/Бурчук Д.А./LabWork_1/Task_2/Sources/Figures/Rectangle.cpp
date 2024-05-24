#include "../../Headers/Rectangle.h"


Rectangle::Rectangle(QWidget *parent) : Figure(parent, std::vector<QPointF>()) {
    this->setParent(parent);

    this->_xRadius = 0;

    this->_yRadius = 0;

    for (int i = 0; i < 4; i++) { points.emplace_back(0, 0); }

}


void Rectangle::draw(QPainter *painter) {

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


void Rectangle::drawMove(QMouseEvent *event) {
    points[0] = _insertionPoint;

    points[1] = QPoint(event->x(), _insertionPoint.y());

    points[2] = event->pos();

    points[3] = QPoint(_insertionPoint.x(), event->y());

    this->_polygon.clear();

    this->_polygon << points[0] << points[1] << points[2] << points[3];

    this->_xRadius = (int) ((event->x() - this->_insertionPoint.x())) / 2;
    this->_yRadius = (int) ((event->y() - this->_insertionPoint.y())) / 2;

    this->_center->setX(this->_insertionPoint.x() + this->_xRadius);

    this->_center->setY(this->_insertionPoint.y() + this->_yRadius);

    findPerimeter();

    findArea();

    update();
}


void Rectangle::findArea() {
    this->_area = qAbs(_xRadius * _yRadius) * 4;
}


void Rectangle::findPerimeter() {
    this->_perimeter = (qAbs((_xRadius) + qAbs(_yRadius)) * 4);
}