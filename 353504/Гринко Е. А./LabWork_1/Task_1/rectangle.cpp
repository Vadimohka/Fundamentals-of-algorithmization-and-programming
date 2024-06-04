#include "rectangle.h"

Rectangle::Rectangle()
{
    setRect(0, 0, 50,100);
    timer1=new QTimer(this);
    connect(timer1, &QTimer::timeout, this, &Rectangle::moveRight);

    timer1->setInterval(10);
    timer2=new QTimer(this);
    connect(timer2, &QTimer::timeout, this, &Rectangle::moveLeft);
    timer2->setInterval(10);
}

void Rectangle::moveLeft()
{
    qreal currentX = pos().x();
    qreal newX = currentX - 1;
    qreal currentY = pos().y();

    if (newX >= 0) {
        timer2->start();
        timer1->stop();
        setPos(newX, currentY);
    } else {
        setPos(0, currentY);
        timer2->stop();
    }
}

void Rectangle::moveRight()
{
    qreal currentX = pos().x();
    qreal newX = currentX + 1;
    qreal currentY = pos().y();
    qreal maxX = scene()->sceneRect().width()-rect().width();

    if (newX <= maxX) {

        timer1->start();
        timer2->stop();
        setPos(newX, currentY);
    } else {
        timer1->stop();
        setPos(maxX, currentY);
    }
}
void Rectangle::Stop()
{
    if (timer1 != nullptr && timer1->isActive()) {
        timer1->stop();
    }
    if (timer2 != nullptr && timer2->isActive()) {
        timer2->stop();
    }
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QRectF rect=boundingRect();
    painter->setPen(QPen(Qt::black,2));
    painter->drawRect(rect);
}




Rectangle::~Rectangle()
{
    delete timer1;
    delete timer2;
}
