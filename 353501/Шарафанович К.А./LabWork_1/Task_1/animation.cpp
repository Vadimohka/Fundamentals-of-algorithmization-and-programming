#include "moving_rectangle.h"

moving_rectangle::moving_rectangle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) :
    QGraphicsRectItem(x,y,width,height, parent) {
    maxPosX = 200;
    minPosX = -200;
    timerRight = new QTimer;
    timerLeft = new QTimer;
    connect(timerRight, &QTimer::timeout, this, &moving_rectangle::timerRightTimeout);
    connect(timerLeft, &QTimer::timeout, this, &moving_rectangle::timerLeftTimeout);
}

void moving_rectangle::move_right() {
    if (!timerRight->isActive()) {
        timerRight->start(15);
    }
}

void moving_rectangle::move_left() {
    if (!timerLeft->isActive()) {
        timerLeft->start(15);
    }
}

void moving_rectangle::timerRightTimeout() {
    coordinates.setX(coordinates.x() + 5);
    setPos(coordinates);
    if (coordinates.x() <= maxPosX && coordinates.x() >= minPosX) {
        update();
    } else {
        timerRight->stop();
    }
}

void moving_rectangle::timerLeftTimeout() {
    coordinates.setX(coordinates.x() - 5);
    setPos(coordinates);
    if (coordinates.x() <= maxPosX && coordinates.x() >= minPosX) {
        update();
    } else {
        timerLeft->stop();
    }
}
