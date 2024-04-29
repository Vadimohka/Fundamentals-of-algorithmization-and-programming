#include "flagok.h"

Flagok::Flagok(QWidget *parent) :
    MovingRectangle(parent)
{
    this->setParent(parent);
}


void Flagok::paintEvent(QPaintEvent *event) {
    QPainter *painter = new QPainter;
    painter->begin(this);
    painter->setBrush(Qt::red);
    QPolygon flag;
    flag << QPoint(350, 400) << QPoint(450, 375) << QPoint(350, 350);
    painter->drawPolygon(flag);
    painter->end();
}

