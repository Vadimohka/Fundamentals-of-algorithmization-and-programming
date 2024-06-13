#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QWidget>
#include "square.h"
#include "bullet.h"
#include "QDebug"
#include "steelwall.h"

class Tank : public Square
{

public:
    Tank(qint8 x, qint8 y, QGraphicsObject *parent = 0);
    ~Tank();
    void rotate(Direction direction);
    virtual void move(qint64 stepSize);
    virtual void shoot(bool isDD = false);
    virtual void takeDamage(qint8 damage);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Direction getDirection();
protected:
    bool isShootEnabled = true;
    QTimer *reloadTimer;
    const qint8 maxhp = 5;
    qint8 hp;
    Direction direction;
    QRectF boundingRect() const override;
protected slots:
    void shootTimerTimeout();
};

#endif // TANK_H
