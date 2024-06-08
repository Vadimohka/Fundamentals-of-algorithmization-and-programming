#include "KeyObject.h"

KeyObject::KeyObject(int w, int h, QGraphicsObject *parent)
    : QGraphicsObject(parent), w(w), h(h)  {
    color = Qt::white;
}

void KeyObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(Qt::NoPen);
    painter->setBrush(color);
    painter->drawRoundedRect(boundingRect(), 12, 12);
}

QRectF KeyObject::boundingRect() const {
    return QRectF(-w / 2.0, -h / 2.0, w, h);
}

void KeyObject::setColor(QColor color) {
    this->color = color;
}
