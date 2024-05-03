#include "pen.h"

Pen::Pen(QPointF point, QObject *parent) : Figure(point,parent)
{
    timer = new QTimer();
    timer->start();
    timer->setInterval(15);
}

void Pen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));
    painter->drawEllipse(valueFirstPoint().x(), valueFirstPoint().y(), 5,5);
    painter->drawEllipse(valueSecondPoint(), 5 , 5);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Pen::draw(QPainter *painter) {
    painter->drawEllipse(valueSecondPoint(), 5 , 5);
    timer->stop();
}
