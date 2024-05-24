#include "wheel.h"
#include "qpainter.h"

Wheel::Wheel()
{
    timer = new QTimer(this);
    timer -> setInterval(3);
    connect(timer, &QTimer::timeout, this, &Wheel::Start);
}

Wheel::~Wheel()
{

}

void Wheel::Start()
{
    timer -> start();
    qreal x = pos().x();
    qreal y = pos().y();
    qreal new_x = x + 1;
    setPos(new_x, y);
}

void Wheel::Restart()
{
    timer ->stop();
    setPos(10, 200);
}

