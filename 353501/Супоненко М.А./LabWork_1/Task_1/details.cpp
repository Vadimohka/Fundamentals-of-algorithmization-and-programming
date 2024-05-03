#include "details.h"
#include <QPainter> 
#include <QTimer>


details::details(): timer(new QTimer(this)) {
    timer->start(10);
    connect(timer, &QTimer::timeout, this, &details::onTimer);
    x = 0;
}

QRectF details::boundingRect() const {
    return QRectF(0, 0, 10, 10);
}

void details::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::red);
    painter -> drawEllipse(-580 + x, 100, 80, 50);

    painter->setBrush(Qt::green);
    painter -> drawEllipse(-500 + x, 100, 80, 50);

    painter->setBrush(Qt::yellow);
    painter -> drawEllipse(-540 + x, 60, 80, 50);

    painter->setBrush(Qt::yellow);
    painter -> drawEllipse(-405 + x, 140, 10, 20);

    painter->setBrush(Qt::black);
    painter -> drawEllipse(-580 + x, 200, 50, 50);

    painter->setBrush(Qt::black);
    painter -> drawEllipse(-475 + x, 200, 50, 50);
}

void details::onTimer() {
    if (x == 1000) { x = 0; }
    x += 1;
    update();
}