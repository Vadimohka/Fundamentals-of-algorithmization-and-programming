#ifndef GOOMBA_H
#define GOOMBA_H
#include <QGraphicsItem>
#include <QPixmap>
#include "objecttype.h"

class Goomba : public QGraphicsItem
{
public:
    enum { Type = UserType + goombaType };
    Goomba(QRectF platformRect, int direction,QGraphicsItem *parent = 0);
    void nextFrame3();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;
    void handleCollosionWithGoomba();
private:

    int mCurrentFrame3;
    QPixmap mPixmap3;
    QRectF mPlatform;
    int mDirection;

};
#endif // GOOMBA_H
