#ifndef SHIP_H
#define SHIP_H

#include <QWidget>
#include <QPainter>
#include "Rectangle.h"


class Ship : public Rectangle, public QObject
{
public:
    Ship(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SHIP_H
