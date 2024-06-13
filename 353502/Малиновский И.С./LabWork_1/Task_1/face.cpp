#include "face.h"

Face::Face(QWidget* parent)
    : MovingEllipse(parent), mouthOpen(false), eyeDx(0), eyeDy(0) {}

void Face::openMouth() {
    mouthOpen = true;
    update();
}

void Face::closeMouth() {
    mouthOpen = false;
    update();
}

void Face::moveEyes(int dx, int dy) {
    eyeDx += dx;
    eyeDy += dy;
    update();
}

void Face::paintEvent(QPaintEvent* event) {
    MovingEllipse::paintEvent(event);

    QPainter painter(this);

    // Draw eyes
    painter.setBrush(Qt::white);
    painter.drawEllipse(x + 20 + eyeDx, y + 20 + eyeDy, 20, 20);
    painter.drawEllipse(x + 60 + eyeDx, y + 20 + eyeDy, 20, 20);

    painter.setBrush(Qt::black);
    painter.drawEllipse(x + 30 + eyeDx, y + 30 + eyeDy, 10, 10);
    painter.drawEllipse(x + 70 + eyeDx, y + 30 + eyeDy, 10, 10);

    // Draw mouth
    if (mouthOpen) {
        painter.drawEllipse(x + 35, y + 60, 30, 20);
    } else {
        painter.drawLine(x + 35, y + 70, x + 65, y + 70);
    }
}
