#ifndef MOVINGRECT_H
#define MOVINGRECT_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h>

class movingRect: public QGraphicsItem
{
public:
    movingRect();
    void move();
    int x = 0, y = 0, w = 1, h = 1;
    short mx = 0, my = 0;

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:

};

#endif // MOVINGRECT_H
