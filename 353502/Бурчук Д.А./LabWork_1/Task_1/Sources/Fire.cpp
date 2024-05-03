#include "../Headers/Fire.h"

Fire::Fire(QWidget* parent) :
        QWidget{}
{
    this->setParent(parent);

    this->hide();

    timer->setInterval(10);
}


void Fire::paintEvent(QPaintEvent * event)
{
    QPainter * painter = new QPainter;

    QPixmap* firePicture = new QPixmap("../Pictures/FIRE.png");

    QRect* fireSize = new QRect(QPoint(0,0),QPoint(30,45));

    painter->begin(this);

    painter->drawPixmap(*fireSize, *firePicture);

    painter->end();
}

slots void Fire::MoveObject()
{
    timer->start();

    this->show();

    Fire::connect(timer, SIGNAL(timeout()),this, SLOT(Up()));
}


slots void Fire::StopMoving()
{
    timer->stop();

    this->hide();

    Fire::disconnect(timer, SIGNAL(timeout()),this, SLOT(Up()));
}


void slots Fire::Up()
{
    this->move(this->x(),this->y()-1);
}

