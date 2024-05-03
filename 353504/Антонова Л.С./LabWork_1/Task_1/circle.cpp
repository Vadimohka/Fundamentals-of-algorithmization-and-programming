#include <QPainter>
#include <QKeyEvent>
#include "circle.h"

Circle::Circle(QWidget *parent) : QWidget(parent) {
    x = 200;
    y = 200;
    r = 150;

    setFocusPolicy(Qt::StrongFocus);
}

void Circle::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    draw(&painter);
}

void Circle::draw(QPainter *painter) {
    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter->setPen(pen);
    painter->drawEllipse(QPointF(x, y), r, r);
}

void Circle::keyPressEvent(QKeyEvent *event) {
    int step = 10;
    int newX = x, newY = y;
    switch (event->key()){
    case Qt::Key_Left:
        newX -= step;
        break;
    case Qt::Key_Right:
        newX += step;
        break;
    case Qt::Key_Up:
        newY -= step;
        break;
    case Qt::Key_Down:
        newY += step;
        break;
    }

    if(newX - r >= 0 && newX + r <= width() && newY - r >= 0 &&
        newY + r <= height()){
        x = newX;
        y = newY;
    }

    update();
}
