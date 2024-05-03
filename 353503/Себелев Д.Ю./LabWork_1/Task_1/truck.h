#ifndef TRUCK_H
#define TRUCK_H

#include "moveablerect.h"
#include <QGraphicsItem>


class Truck : public MoveableRect
{
public:
    Truck(QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    float sign;

public slots:
    void rotate() override;

private:
    MoveableRect *back;
    QPoint points[9];
    QPolygon base;
    QRect wheel1;
    QRect wheel2;
    QRect wheel3;
    QRect rim1;
    QRect rim2;
    QRect rim3;
    QPolygon window;
    QRect door;
    float angle;
    float mult;
};

#endif // TRUCK_H
