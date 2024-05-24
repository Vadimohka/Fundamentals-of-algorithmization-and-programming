#include "metronome.h"

Metronome::Metronome(QObject *parent) : QObject(parent)
{
    ticker = new Ticker(this);
    timer = new Timer(this);
    connect(timer, &Timer::timeout, ticker, &Ticker::playSound);
}
