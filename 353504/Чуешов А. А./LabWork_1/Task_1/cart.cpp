#include "cart.h"

Cart::Cart(QObject *parent) : MovingRectangle()
{
    // Create the wheel objects
    QGraphicsEllipseItem *wheel1 = new QGraphicsEllipseItem(-30, 50, 30, 30, this);
    QGraphicsEllipseItem *wheel2 = new QGraphicsEllipseItem(80, 50, 30, 30, this);

    // Set the wheel brush color to black
    wheel1->setBrush(Qt::black);
    wheel2->setBrush(Qt::black);
}

QRectF Cart::boundingRect() const
{
    QRectF rec = QRectF(0, 0, 80, 40);
    int wheelDiameter = rec.height() / 2;
    int wheelDistance = rec.width() / 4;
    rec = rec.adjusted(-wheelDistance, 0, wheelDistance, wheelDiameter);
    return rec;
}

void Cart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    QBrush brush(Qt::gray);
    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}
