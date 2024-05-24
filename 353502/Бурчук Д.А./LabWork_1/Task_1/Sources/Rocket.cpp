#include "../Headers/Rocket.h"

Rocket::Rocket(QWidget *parent) :
        MovingLine(parent)
{
    this->setParent(parent);
}


void Rocket::paintEvent(QPaintEvent * event)
{
    QPainter * painter = new QPainter;

    QPixmap* rocketPicture = new QPixmap("../Pictures/Rocket.jpeg");

    QRect* rocketSize = new QRect(QPoint(0,0),QPoint(100,150));

    painter->begin(this);

    painter->drawPixmap(*rocketSize, *rocketPicture);

    painter->end();

}
