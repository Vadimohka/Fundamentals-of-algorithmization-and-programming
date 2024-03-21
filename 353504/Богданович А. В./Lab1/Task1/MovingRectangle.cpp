#include "MovingRectangle.h"
#include <QMessageBox>

MovingRectangle::MovingRectangle(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 100);
}

void MovingRectangle::paintEvent(QPaintEvent *)
{

}

void MovingRectangle::moveRight() {
    int a = x();
    a += 10;
    if (a < 1850) {
        move(a, y());
    } else {
        move(-399, y());
    }
}

void MovingRectangle::moveLeft() {
    int a = x();
    a -= 10;
    if (a > -400) {
        move(a, y());
    } else {
        move(1849, y());
    }

}





