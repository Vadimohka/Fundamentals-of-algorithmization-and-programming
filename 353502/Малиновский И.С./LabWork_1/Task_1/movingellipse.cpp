#include "movingellipse.h"

MovingEllipse::MovingEllipse(QWidget* parent)
    : QWidget(parent), x(50), y(50), width(100), height(50) {
    setFixedSize(200, 200);
}

void MovingEllipse::moveEllipse(int dx, int dy) {
    x += dx;
    y += dy;
    update();
}

void MovingEllipse::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(x, y, width, height);
}
