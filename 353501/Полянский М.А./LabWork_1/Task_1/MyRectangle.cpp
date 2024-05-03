#include "MyRectangle.h"
#include <QPainter>

myRectangle::myRectangle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent) {}

QRectF myRectangle::boundingRect() const {
    return QRectF(100,  -75, 300,150);
}

void myRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::yellow);
    painter->drawRect(boundingRect());
}


