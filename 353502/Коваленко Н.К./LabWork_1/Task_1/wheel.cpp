#include "wheel.h"
#include <QtMath>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

Wheel::Wheel(QGraphicsScene *parent) :
    Circle(parent)
{
    // center.setX(x0/2);
    // center.setY(y0/2);
    // this->Circle::setPos(center);
    // this->Circle::setTransformOriginPoint(center);
    // step = x0/10;
}

Wheel::~Wheel(){}

void Wheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if(isrotated){
        painter->rotate(45);
    }
    painter->setPen(QPen(QColor(0,0,0,0)));
    painter->setBrush(QBrush(QColor(138,46,225)));

    QPainterPath *tire = new QPainterPath();
    tire->setFillRule(Qt::FillRule::OddEvenFill);
    QPainterPath *disc = new QPainterPath();
    disc->setFillRule(Qt::FillRule::OddEvenFill);
    QPainterPath *obod = new QPainterPath();
    obod->setFillRule(Qt::FillRule::OddEvenFill);

    tire->addEllipse(-150,-150, 300,300);
    tire->closeSubpath();
    painter->setBrush(QBrush(QColor(102,0,153)));
    painter->drawPath(*tire);

    obod->addEllipse(-140,-140,280,280);
    obod->closeSubpath();
    painter->setBrush(QBrush(QColor(42,141,156)));
    painter->drawPath(*obod);

    disc->addRect(0, -150, 10, 150);
    disc->addRect(0, 10, 10, 130);
    disc->addRect(-150, 0, 290 ,10);
    disc->closeSubpath();
    painter->setBrush(QBrush(QColor(102,0,153)));
    painter->drawPath(*disc);

}
