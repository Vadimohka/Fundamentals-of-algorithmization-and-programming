#ifndef MOVELINE_H
#define MOVELINE_H

#include <QObject>
#include <QGraphicsLineItem>
#include <QTimer>

class MoveLine : public QObject, public QGraphicsLineItem
{
public:
    QTimer *timer;
    MoveLine();
    ~MoveLine();
    void Start();
    void Restart();
};

#endif // MOVELINE_H
