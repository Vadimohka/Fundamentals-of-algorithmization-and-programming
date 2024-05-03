#include "baloon.h"
#include <QPainter>
#include <QSlider>
#include <QLineF>
#include <QPoint>

Balloon::Balloon(int x, int y, int hei, int wid, QGraphicsEllipseItem* parent)
    : Ellips(x, y, wid, hei, parent), line(QPointF(x+wid/2, y+hei), QPointF(x+wid/2, y+hei+80)), originalPos(x,y), originalWidth(wid), poped(false)
{timer = new QTimer(this);
 connect(timer, &QTimer::timeout, this, &Balloon::shrink);
    polygon<<QPoint(-150,410)<<QPoint(-155,420)<<QPoint(-145,420);
}


void Balloon::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->eraseRect(0,0,10000,10000);


    if (poped)
    {
    painter->setBrush(Qt::white);
    painter->setPen(QPen(Qt::white, 2));
    }
    else
    {
        painter->setBrush(Qt::blue);
        painter->setPen(QPen(Qt::black, 2));
    }



    painter->drawEllipse(boundingRect());
    painter->drawPolygon(polygon);



    painter->drawLine(line);
}


void Balloon::shake(int value)
{
    QSlider* slider = qobject_cast<QSlider*>(sender());
    if (!slider) return;

    int percentage = (value * 100) / slider->maximum();
     int dx=0, dy=0;

    if (percentage<=50) return;
    else if (percentage>=50 && percentage<=80){
    dx = arc4random()%5-2;
    dy = arc4random()%5-2;
    }
    else{
    dx = arc4random()%8-4;
    dy = arc4random()%8-4;
    }


    int newX = x() + dx;
    int newY = y() + dy;


    int relX = originalPos.x()+200;
    if (newX < relX-6) newX = relX-6;
    if (newX > relX+6) newX = relX+ 6;

    setPos(newX, newY);
    setPos(x()+dx, y()+dy);

}

void Balloon::reset()
{
    setPos(originalPos.x()+200, originalPos.y()-260);
    setRect(-originalWidth-100, 260, originalWidth, rect().height());
    poped = false;
}

void::Balloon::pop()
{
    timer->start(50);
}

void Balloon::shrink() {
    QRectF r = rect();
    if (r.width() < 130) {
        qreal shrinkAmount = originalWidth / 10;
        r.setWidth(r.width() + shrinkAmount);
        r.moveLeft(r.left() - shrinkAmount / 2);
        setRect(r);
    } else {
        timer->stop();
        poped=true;
        update();
    }
}

void Balloon::updatePosition(int value) {
    // Assuming that higher values from the slider should move the balloon up
    QSlider* slider = qobject_cast<QSlider*>(sender());

    int percentage = (value * 100) / slider->maximum();

    if (!slider) return;
    setY(-value);

    if (percentage==100) this->pop();
}


