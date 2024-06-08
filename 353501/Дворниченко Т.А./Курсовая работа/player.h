#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QPixmap>

class Player : public QGraphicsItem
{
public:
     Player(QGraphicsItem *parent = 0);
     ~Player();
    int direction() const;
    void addDirection(int direction);
    void nextFrame();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool isTouchingFoot(QGraphicsItem *item);
    bool isTouchingHead(QGraphicsItem *item);
    bool isTouchingPlatform(QGraphicsItem *item);



    void stand();
    void jump();
    void walk();
    void fall();

    bool isFalling();



private:
    enum State {
         Standing = 0,
         Walking,
         Jumping,
         Falling
    };



    int m_direction;
    int mCurrentFrame;
    State mState;
    QPixmap mPixmap;
    QPixmap mWalkPixmap;
    QPixmap mStandingPixmap;
    QPixmap mJumpPixmap;

};


#endif // PLAYER_H
