#pragma once

#include <QGraphicsObject>

class RectArray : public QGraphicsObject
{

public:
    RectArray();
    ~RectArray();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int number = 1;

private:


};