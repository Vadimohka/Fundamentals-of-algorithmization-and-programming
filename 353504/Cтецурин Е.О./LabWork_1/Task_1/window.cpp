#include "window.h"
#include <QPainter>

Window::Window(QWidget *parent) : MovingRectangle(parent)
{
    setFixedSize(200, 200);
    isOpenWin =false;
}

void Window::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int wWidth = 100;
    int wHeight = 200;
    QRect wRect(0, 0, wWidth, wHeight);

    painter.fillRect(wRect, Qt::darkCyan);
}

void Window::paintEvent1(QPaintEvent *)
{
    QPainter painter(this);

    int wWidth = 100;
    int wHeight = 200;
    QRect wRect(0, 0, wWidth, wHeight);

    painter.fillRect(wRect, Qt::darkCyan);
}

void Window::togglew()
{
    isOpenWin=!isOpenWin;
}
