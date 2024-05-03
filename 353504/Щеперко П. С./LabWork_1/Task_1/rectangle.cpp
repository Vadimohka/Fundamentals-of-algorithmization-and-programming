#include "rectangle.h"

Rectangle::Rectangle(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 100);
}

void Rectangle::paintEvent(QPaintEvent *)
{

}

void Rectangle::moveRight()
{
    int a = x();
    a += 10;
    if (a < 1600) {
        move(a, y());
    }
}

void Rectangle::moveLeft() {
    int a = x();
    a -= 10;
    if (a > 100) {
        move(a, y());
    }
}
