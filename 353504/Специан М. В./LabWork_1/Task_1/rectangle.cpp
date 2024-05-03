#include "rectangle.h"


Rectangle::Rectangle(int x, int y, int width, int height, QWidget* parent)
    : QWidget(parent), x(x), y(y), width(width), height(height)
{
    timerUp = new QTimer(this);
    connect(timerUp, &QTimer::timeout, this, &Rectangle::movingUp);

    timerDown = new QTimer(this);
    connect(timerDown, &QTimer::timeout, this, &Rectangle::movingDown);
}

Rectangle::~Rectangle()
{

}

void Rectangle::startMoveDown()
{
    timerDown->start(15);
}

void Rectangle::startMoveUp()
{
    timerUp->start(15);
}

void Rectangle::movingDown()
{
    y += 1;
    update();

    if (y >= buffY + height)
    {
        timerDown->stop();
        buffY = y;
    }
}

void Rectangle::movingUp()
{
    y -= 1;
    update();

    if (y <= buffY - height)
    {
        timerUp->stop();
        buffY = y;
    }
}
