#include "Rect.h"
#include <QPainter> 
#include <QTimer>


Rect::Rect(): timer(new QTimer(this)) {
    timer->start(10);
    connect(timer, &QTimer::timeout, this, &Rect::onTimer);
    x = 0;
}

QRectF Rect::boundingRect() const {
    return QRectF(0, 0, 10, 10);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::blue);
    painter -> drawRect(-600 + x, 120,200, 100);
}

void Rect::onTimer() {
    if (x == 1000) { x = 0; }
    x += 1;
    update();
}