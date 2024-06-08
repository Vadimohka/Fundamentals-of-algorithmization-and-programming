#include "timer.h"
#include <QTimer>
#include <QFont>
#include<QFontDatabase>

Timer::Timer(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    timeCount = 0;
    isRunning = true;
    int id = QFontDatabase::addApplicationFont(":font/CoinCount2.ttf");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("0:00"));
    setDefaultTextColor(Qt::black);
    setFont(QFont("CoinCount2", 30));
    startTimer(1000);
}

void Timer::timerEvent(QTimerEvent *) {
    decrease();
}
void Timer::restart() {
    timeCount = 0;
    isRunning = true;
}
void Timer::stop() {
    isRunning = false;
}
bool isRunning;
void Timer::decrease() {
    if (isRunning) {
        int minutes = timeCount / 60;
        int seconds = timeCount % 60;

        setPlainText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));

        timeCount++;
    }
}
QString Timer::getTime() {
    int minutes = timeCount / 60;
    int seconds = timeCount % 60;
    return QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
}
