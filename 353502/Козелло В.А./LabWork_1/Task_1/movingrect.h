#ifndef MOVINGRECT_H
#define MOVINGRECT_H

#include <QGraphicsItem>
#include <QPainter>

class movingRect : public QGraphicsItem
{
public:
    movingRect();
    ~movingRect();

    void moveRight();
    void moveDown();
    void moveLeft();
    void moveUp();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MOVINGRECT_H
