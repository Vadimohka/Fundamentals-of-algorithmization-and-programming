#ifndef SMALLMARIO_H
#define SMALLMARIO_H


#include <QGraphicsItem>
#include <QPixmap>

class SmallMario : public QGraphicsItem
{
public:

     SmallMario(QGraphicsItem *parent = 0);
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
         Standing = 2,
         Walking=3,
         Jumping,
         Falling=4,
         Shrink
    };



    int m_direction;
    int mCurrentFrame;
    State mState;
    QPixmap mPixmap;
    QPixmap mWalkPixmap;
    QPixmap mStandingPixmap;
    QPixmap mShrinkPixmap;
    QPixmap mJumpPixmap;

};





#endif // SMALLMARIO_H
