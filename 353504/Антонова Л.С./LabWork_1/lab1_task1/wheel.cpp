#include "wheel.h"
#include <QPainter>
#include <QKeyEvent>
#include <QPainterPath>

Wheel::Wheel(Circle *parent) : Circle(parent) {
    angle = 0.0;
    press = 0;

    setFocusPolicy(Qt::StrongFocus);
}

void Wheel::paintEvent(QPaintEvent *event){
    Circle::paintEvent(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    drawWheel(&painter);
}

void Wheel::rotate(){
    double step = 0.5;
    if(press){
        angle += step;
    }

    update();
}

void Wheel::drawWheel(QPainter *painter){
    rotate();
    const int num = 8;
    const qreal length = r;

    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter->setPen(pen);

    QPainterPath path;                     \
    path.addEllipse(QPointF(x, y), r, r);
    path.addEllipse(QPointF(x, y), 175.0, 175.0);
    painter->fillPath(path, Qt::black);

    for(int i = 0; i < num; ++i){
        qreal rad = 2 * M_PI * i / num + angle;
        qreal x_new = x + length * qCos(rad);
        qreal y_new = y - length * qSin(rad);

        painter->drawLine(QPointF(x, y), QPointF(x_new, y_new));
    }
}

void Wheel::keyPressEvent(QKeyEvent *event) {
    int step = 10;
    int newX = x, newY = y;
    switch (event->key()){
    case Qt::Key_Left:
        newX -= step;
        press = 1;
        break;

    case Qt::Key_Right:
        newX += step;
        press = 1;
        break;

    case Qt::Key_Up:
        newY -= step;
        press = 1;
        break;

    case Qt::Key_Down:
        newY += step;
        press = 1;
        break;
    }
    if(newX - r >= 0 && newX + r <= width() && newY - r >= 0 && newY + r <= height()){
        x = newX;
        y = newY;
    }
    update();
}

void Wheel::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||                                                     event->key() == Qt::Key_Up || event->key() == Qt::Key_Down){
        press = 0;
    }
    update();
}
