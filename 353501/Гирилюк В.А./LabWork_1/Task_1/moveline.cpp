#include "moveline.h"
#include "qpainter.h"

MoveLine::MoveLine()
{
    timer = new QTimer(this);
    timer->setInterval(2);
    connect(timer, &QTimer::timeout, this, &MoveLine::Start);
}

MoveLine::~MoveLine()
{

}

void MoveLine::Start()
{
    timer->start();
    qreal current_x = pos().x();
    qreal current_y = pos().y();
    qreal new_y = current_y - 1;
    setPos(current_x, new_y);
}

void MoveLine::Restart()
{

    timer->stop();
    setPos(490, 500);

}
