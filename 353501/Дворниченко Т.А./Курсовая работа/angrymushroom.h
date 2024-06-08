#ifndef ANGRYMUSHROOM_H
#define ANGRYMUSHROOM_H
#include <QGraphicsItem>
#include <QPixmap>
#include "objecttype.h"

class GiantGoomba : public QGraphicsItem
{
public:
    enum { Type = UserType + giantGoombaType };
    GiantGoomba(QGraphicsItem *parent = 0);
    int type() const;
    void nextFrame12();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    int mCurrentFrame12;
    QPixmap mPixmap12;
};
#endif // ANGRYMUSHROOM_H
