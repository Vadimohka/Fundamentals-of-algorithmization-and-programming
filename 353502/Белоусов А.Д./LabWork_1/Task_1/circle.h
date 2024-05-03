#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsItem>
#include <QPainter>

class circle : public QGraphicsItem
{
public:
    circle();
    void setCircle(int x, int y, int radius);

protected:
    float x, y, radius;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // CIRCLE_H
