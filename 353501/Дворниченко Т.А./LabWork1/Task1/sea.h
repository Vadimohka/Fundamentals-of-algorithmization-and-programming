#ifndef SEA_H
#define SEA_H
#include <Rectangle.h>
#include <QPainter>
class Sea: public Rectangle
{
public:
    Sea(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SEA_H
