#include "../../Headers/Square.h"


Square::Square(QWidget *parent) : Figure(parent, std::vector<QPointF>()) {
    this->setParent(parent);

    this->_xRadius = 0;

    this->_yRadius = 0;

    for (int i = 0; i < 4; i++) { points.emplace_back(0, 0); }
}


void Square::draw(QPainter *painter) {

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

    findPerimeter();

    findArea();

    painter->setPen(Qt::black);

    painter->setBrush(Qt::NoBrush);
}


void Square::drawMove(QMouseEvent *event) {
    this->_xRadius = (int) ((event->x() - this->_insertionPoint.x())) / 2;
    this->_yRadius = (int) ((event->y() - this->_insertionPoint.y())) / 2;

    int signX = _xRadius < 0 ? -1 : 1;
    this->_xRadius = signX * qMin(qAbs(_xRadius), qAbs(_yRadius));

    int signY = _yRadius < 0 ? -1 : 1;
    this->_yRadius = signY * qMin(qAbs(_xRadius), qAbs(_yRadius));

    this->_center->setX(this->_insertionPoint.x() + this->_xRadius);

    this->_center->setY(this->_insertionPoint.y() + this->_yRadius);

    points[0] = _insertionPoint;

    points[1] = QPoint(_insertionPoint.x() + 2 * _xRadius, _insertionPoint.y());

    points[2] = QPoint(_insertionPoint.x() + 2 * _xRadius, _insertionPoint.y() + 2 * _yRadius);

    points[3] = QPoint(_insertionPoint.x(), _insertionPoint.y() + 2 * _yRadius);

    this->_polygon.clear();

    this->_polygon << points[0] << points[1] << points[2] << points[3];

    this->_center->setX(this->_insertionPoint.x() + this->_xRadius);

    this->_center->setY(this->_insertionPoint.y() + this->_yRadius);

    findPerimeter();

    findArea();

    update();
}


void Square::findArea() {
    this->_area = qAbs(_xRadius * _yRadius) * 4;
}


void Square::findPerimeter() {
    this->_perimeter = (qAbs((_xRadius) + qAbs(_yRadius)) * 4);
}