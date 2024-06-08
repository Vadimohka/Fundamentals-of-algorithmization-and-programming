#ifndef TIMER_H
#define TIMER_H

#include <QGraphicsTextItem>

class Timer : public QGraphicsTextItem {
public:
    Timer(QGraphicsItem *parent = nullptr);
    void stop();
    void restart();
    QString getTime();

protected:
    void timerEvent(QTimerEvent *) override;

private:
    int timeCount;
    bool isRunning;
    void decrease();
};

#endif // TIMER_H
