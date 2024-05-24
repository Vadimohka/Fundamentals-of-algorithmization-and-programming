#ifndef DICE_H
#define DICE_H

#include <QObject>
#include <QRandomGenerator>
#include <QTimer>

class Dice : public QObject
{
    Q_OBJECT
public:
    explicit Dice()
        : m_rollsCount(0)
    {
        m_interval = STARTINTERVAL;
        connect(&m_timer, &QTimer::timeout, this, &Dice::roll);
    }

    void startRolling(int type)
    {
        m_rollsCount = 0;
        m_interval = STARTINTERVAL;
        m_timer.start(m_interval);
        this->type = type;
    }

    void stopRolling() { m_timer.stop(); }

signals:
    void rolled(int type, int value, bool lastRoll);

private slots:
    void roll()
    {
        int result = QRandomGenerator::global()->bounded(1, type + 1);
        emit rolled(type, result, m_rollsCount >= MAXROLLS - 1);
        m_rollsCount++;
        if (m_rollsCount >= MAXROLLS) {
            stopRolling();
        }
        m_interval *= INCREMENT;
        m_timer.setInterval(m_interval);
    }

private:
    QTimer m_timer;
    int m_interval;
    int m_rollsCount;
    int type;
    const int MAXROLLS = 30;
    const double INCREMENT = 1.1;
    const int STARTINTERVAL = 10;
};

#endif // DICE_H
