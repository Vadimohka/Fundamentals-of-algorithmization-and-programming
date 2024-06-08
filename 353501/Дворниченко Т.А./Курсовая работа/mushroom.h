#ifndef MUSHROOM_H
#define MUSHROOM_H


#include <QGraphicsItem>
#include <QPixmap>
#include "objecttype.h"

class Mushroom : public QGraphicsItem
{
public:
    enum { Type = UserType + mushroomType };
    Mushroom(QRectF platformRect, int direction,QGraphicsItem *parent = 0);
    void nextFrame();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;
private:

    int mCurrentFrame;
    QPixmap mPixmap;
    QRectF mPlatform;
    int mDirection;

};

#endif // MUSHROOM_H
