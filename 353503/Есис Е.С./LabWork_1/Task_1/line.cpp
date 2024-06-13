#include "line.h"
#include <QPainter>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qpoint.h>
#include <qtimer.h>

Line::Line() : timer(this) {
    connect(&timer, &QTimer::timeout, this, &Line::Tick);

    wx = 2;
    x = 0;

    dir = 0;

    timer.setInterval(20);
    timer.start();
}

void Line::Tick() {
    setPos(pos() + QPoint(wx * dir, 0));
    x += wx * dir;
    if(x >= 0 && dir == 1)
        dir = 0;
    if (x <= -60 && dir == static_cast<qint8>(-1))
        dir = 0;
    update();
}

void Line::Forward()
{
    dir = 1;
}

void Line::Back()
{
    dir = -1;
}





QRectF Line::boundingRect() const{
    return QRectF(-150 /*+ x*/, -100, 300, 400);
}

void Line::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::gray);
    painter->drawRect(0,200,60, 150);
}
