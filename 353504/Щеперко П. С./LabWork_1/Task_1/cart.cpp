#include "cart.h"

Cart::Cart(QWidget *parent) : Rectangle(parent)
{
    setFixedSize(400, 152);
    angle = 0;
}

void Cart::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QRect rect(0, 0, 200, 130);
    painter.fillRect(rect, Qt::black);

    painter.setBrush(Qt::black);

    painter.save();
    painter.translate(20, 130);
    painter.rotate(angle);
    painter.drawEllipse(QPoint(0, 0), 20, 20);
    painter.drawLine(QPoint(-20, 0), QPoint(20, 0));
    painter.drawLine(QPoint(0, -20), QPoint(0, 20));
    painter.restore();

    painter.save();
    painter.translate(180, 130);
    painter.rotate(angle);
    painter.drawEllipse(QPoint(0, 0), 20, 20);
    painter.drawLine(QPoint(-20, 0), QPoint(20, 0));
    painter.drawLine(QPoint(0, -20), QPoint(0, 20));
    painter.restore();

}

void Cart::moveCart() {
    Rectangle::moveRight();
    angle += 10;
}

void Cart::moveBackCart() {
    Rectangle::moveLeft();
    angle -= 10;
}
