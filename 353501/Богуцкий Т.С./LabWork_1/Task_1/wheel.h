#ifndef WHEEL_H
#define WHEEL_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>



class Wheel : public QObject, public QGraphicsRectItem
{
public:
    QTimer *timer;
    Wheel();
    ~Wheel();
    void Start();
    void Restart();
};

#endif // WHEEL_H

