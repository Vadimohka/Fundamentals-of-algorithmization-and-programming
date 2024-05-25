#include "rectangle.h"

Rectangle::Rectangle(QWidget *parent) : CommonFigure(parent) {
    this->setParent(parent);

}

void Rectangle::draw(QPainter *painter) {
    painter->setPen(Qt::black);

    painter->drawPolygon(polygon);

    painter->setBrush(Qt::black);

    if (height != 0 && width != 0) {
        painter->drawEllipse(this->centerPoint.x() - 2, this->centerPoint.y() - 2, 4, 4);

    }
    painter->setBrush(Qt::NoBrush);
}

void Rectangle::drawMoveEvent(QMouseEvent *event) {
    polygon.clear();

    points.clear();

    this->width = (event->x() - insertionPoint.x()) / 2;

    this->height = (event->y() - insertionPoint.y()) / 2;

    this->centerPoint.setX(insertionPoint.x() + width);

    this->centerPoint.setY(insertionPoint.y() + height);

    points.emplace_back(QPointF(insertionPoint.x(), insertionPoint.y()));

    points.emplace_back(QPointF(insertionPoint.x(), insertionPoint.y() + 2 * height));

    points.emplace_back(QPointF(insertionPoint.x() + 2 * width, insertionPoint.y() + 2 * height));

    points.emplace_back(QPointF(insertionPoint.x() + 2 * width, insertionPoint.y()));
}
