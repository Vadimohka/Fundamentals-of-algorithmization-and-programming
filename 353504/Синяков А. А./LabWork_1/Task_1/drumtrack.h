#ifndef DRUMTRACK_H
#define DRUMTRACK_H
#include "animatedrectangle.h"
#include <QGraphicsItem>
#include<QPainter>
#include "animatedrectangle.h"
class Drumtrack : public Rectangle
{
public:
    Drumtrack(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
protected:
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // DRUMTRACK_H
