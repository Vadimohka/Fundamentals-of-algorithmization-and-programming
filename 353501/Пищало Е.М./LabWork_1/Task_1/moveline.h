#ifndef MOVELINE_H
#define MOVELINE_H

#include <QObject>
#include <QGraphicsLineItem>
#include <QTimer>

class MoveLine : public QObject, public QGraphicsLineItem
{
    QTimer *timer;
public:
    MoveLine();
    ~MoveLine();
    void Start();
    void Restart();
};

#endif // MOVELINE_H
