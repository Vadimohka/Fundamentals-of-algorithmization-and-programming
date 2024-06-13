#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"
#include <QKeyEvent>
#include <QTimer>
#include "powerup.h"

class Player : public Tank
{
    Q_OBJECT
public:
    Player(qint8 x, qint8 y, QGraphicsObject *parent = 0);
    ~Player();
    void enableMovement(Direction direction);
    void takeDamage(qint8 damage) override;
    void shoot(bool isDD = false) override;
    void move(qint64 stepSize) override;
    bool isInGhostForm();
protected:
    const qint8 maxhp = 10;
    void keyPressEvent(QKeyEvent* e) override;
    void keyReleaseEvent(QKeyEvent* e) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    bool isMoveEnabled = false;
    Square::Cell currentCell;
    qint64 stepSize = 4;
    bool isDoubleDamage = false;
    bool isGhost = false;
    QTimer *ghostTimer;
private slots:
    void moveTimerTimeout();
    void ghostTimerTimeout();
signals:
    void updatePos(Square::Cell cell);
    void changePlayerHP(qint8 hp);
};

#endif // PLAYER_H
