#include "samosval.h"

Samosval::Samosval(Rectangle *parent):
    Rectangle {parent}
{
    this->setParent(parent);
}

void Samosval::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.begin(this);
    QPen pen(Qt::blue);
    paint.setBrush(Qt::blue);
    paint.setPen(pen);
    paint.drawLine(200,300,410,300);
    paint.drawRect(410,240,60,60);
    paint.setBrush(Qt::black);
    paint.drawEllipse(225,300,45,45);
    paint.drawEllipse(415,300,45,45);
    paint.end();

}


