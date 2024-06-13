#ifndef MOVINGELLIPSE_H
#define MOVINGELLIPSE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>

class MovingEllipse : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    MovingEllipse(QObject *parent = 0);
    ~MovingEllipse();

public slots:
    virtual void MoveEllipse();


};
#endif // MOVINGELLIPSE_H

