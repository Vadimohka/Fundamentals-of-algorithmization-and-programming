#include "Wagon.h"

Wagon::Wagon(QWidget *parent) : MovingRectangle(parent)
{
    setFixedSize(400, 152);
    angle = 0;
}

void Wagon::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QRect rect(0, 0, 400, 100);
    painter.fillRect(rect, Qt::red);

    painter.setBrush(Qt::black);

    painter.save();
    painter.translate(100, 100);
    painter.rotate(angle);
    painter.drawEllipse(QPoint(0, 0), 50, 50);
    painter.drawLine(QPoint(-50, 0), QPoint(50, 0));
    painter.drawLine(QPoint(0, -50), QPoint(0, 50));
    painter.restore();

    painter.save();
    painter.translate(300, 100);
    painter.rotate(angle);
    painter.drawEllipse(QPoint(0, 0), 50, 50);
    painter.drawLine(QPoint(-50, 0), QPoint(50, 0));
    painter.drawLine(QPoint(0, -50), QPoint(0, 50));
    painter.restore();

}

void Wagon::moveRight() {
    MovingRectangle::moveRight();
    angle += 10;
}

void Wagon::moveLeft() {
    MovingRectangle::moveLeft();
    angle -= 10;
}
