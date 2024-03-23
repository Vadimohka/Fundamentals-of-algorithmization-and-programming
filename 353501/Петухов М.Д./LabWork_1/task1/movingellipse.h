#ifndef MOVINGELLIPSE_H
#define MOVINGELLIPSE_H

#include<QGraphicsEllipseItem>
#include<QObject>
#include <QPointF>
#include <QTimer>

class Movingellipse : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Movingellipse(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
private:
    double coordY;
    QPointF coordinates;
protected:
    QTimer* timer = new QTimer();
    bool isBursted = false;
public slots:
    void move();
    void flyUp();
    void startFly();
    void stopFly();
    void startFlyDown();
    void stopFlyDown();
    void flyDown();
signals:
    void timeToBurst();
};

#endif // MOVINGELLIPSE_H
