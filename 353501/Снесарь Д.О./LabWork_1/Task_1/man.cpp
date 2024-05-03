#include "man.h"

Man::Man()
{

}

QRectF Man::boundingRect() const
{
    return QRectF(0,0,200,300);
}
void Man::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QRectF rec = boundingRect();
    //painter->drawRect(rec);
    QPen pen1(Qt::black);
    pen1.setWidth(7);
    painter->setPen(pen1);
    painter->drawLine(100,80,100,150);
    painter->drawLine(100,150,130,200);
    painter->drawLine(100,150,70,200);
    painter->drawEllipse(75,30,50,50);

}


