#ifndef SHIP_H
#define SHIP_H
#include <QGraphicsObject>
#include <QPainter>

class Ship : public QGraphicsObject
{
public:
    Ship();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // SHIP_H
