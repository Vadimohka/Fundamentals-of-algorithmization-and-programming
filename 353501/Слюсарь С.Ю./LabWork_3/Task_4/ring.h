#ifndef RING_H
#define RING_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QTimer>
#include <QEventLoop>

class Ring : public QGraphicsItem
{
public:
    Ring(int x, int y, int width, int height, int pos);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int pos_;
    QGraphicsItemAnimation *animation;
    QTimeLine *timer;
    void moveTo1(int pos);
    void moveTo2(int pos);
    void moveTo3(int pos);
    int x_;
    int y_;
    int width_;
    int height_;
    int xAnim = 0;
    int yAnim = 0;
    void xChange();

};

#endif // RING_H
