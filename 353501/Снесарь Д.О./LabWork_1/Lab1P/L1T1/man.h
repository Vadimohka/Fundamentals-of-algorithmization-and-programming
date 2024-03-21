#ifndef MAN_H
#define MAN_H

#include <QPainter>
#include <QGraphicsItem>

class Man :public QGraphicsItem
{
public:
    Man();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // MAN_H
