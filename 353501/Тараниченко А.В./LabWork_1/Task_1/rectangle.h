#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>
#include <QGraphicsItem>


class Rectangle : public QGraphicsItem
{
private:
    int x, y, w, h;
public:
    Rectangle();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // RECTANGLE_H
