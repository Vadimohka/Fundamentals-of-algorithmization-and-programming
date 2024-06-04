#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = 0);

signals:
    // sent when the timer finishes to count
    void timeout();

public slots:
    void start();
    void stop();
    void setTickingValue(int val);
    void timerEvent();

private:
    QTimer *timer;
    int tickingValue;
    bool buttonClicked;
};

#endif // TIMER_H

