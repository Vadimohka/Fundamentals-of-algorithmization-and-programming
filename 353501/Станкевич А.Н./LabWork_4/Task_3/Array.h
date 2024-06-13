#pragma once
#include <QGraphicsObject>

class Array : public QGraphicsObject
{
public:
    Array();
    ~Array();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int number = 1;

};
