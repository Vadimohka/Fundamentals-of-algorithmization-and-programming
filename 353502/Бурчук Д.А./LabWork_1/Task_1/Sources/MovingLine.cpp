#include "../Headers/MovingLine.h"


MovingLine::MovingLine(QWidget *parent)
        : QWidget{}
{
    this->setParent(parent);

    timer->setInterval(10);
}


MovingLine::~MovingLine()
{
    delete this->timer;
}


void MovingLine::paintEvent(QPaintEvent * event)
{
    QPainter* painter = new QPainter;
    painter->begin(this);

    QPen redpen(Qt::red);
    redpen.setWidth(4);

    painter->setPen(redpen);

    polygon << QPoint(500,500)
            << QPoint(500,450);

    painter->drawPolygon(polygon);

    painter->end();

}


slots void MovingLine::MoveObject()
{
    timer->start();

    MovingLine::connect(timer, SIGNAL(timeout()),this, SLOT(Up()));
}


slots void MovingLine::StopMoving()
{
    timer->stop();

    MovingLine::disconnect(timer, SIGNAL(timeout()),this, SLOT(Up()));
}


void slots MovingLine::Up()
{
    this->move(this->x(),this->y()-1);
}
