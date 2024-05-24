#include "timer.h"

Timer::Timer(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    timer->stop();
    buttonClicked = false;
}

void Timer::start()
{
    connect(timer, &QTimer::timeout, this, &Timer::timerEvent);
    timer->start(this->tickingValue);
    buttonClicked = true;
}

void Timer::setTickingValue(int val)
{
    this->tickingValue = 60000/ val;
    if (buttonClicked) {
        timer->start(this->tickingValue);
    }
}
void Timer::stop()
{
    timer->stop();
    disconnect(timer, &QTimer::timeout, this, &Timer::timerEvent);
    buttonClicked = false;

}
void Timer::timerEvent()
{
    emit timeout();
}
