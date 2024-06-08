#ifndef TURTLE_H
#define TURTLE_H
#include <QGraphicsItem>
#include <QPixmap>
#include "objecttype.h"

class Turtle : public QGraphicsItem
{
public:
    enum { Type = UserType + turtleType };
    Turtle(QRectF platformRect, int direction,QGraphicsItem *parent = 0);
    void nextFrame6();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;
private:

    int mCurrentFrame6;
    QPixmap mPixmap6;
    QRectF mPlatform;
    int mDirection;
};
#endif // TURTLE_H
