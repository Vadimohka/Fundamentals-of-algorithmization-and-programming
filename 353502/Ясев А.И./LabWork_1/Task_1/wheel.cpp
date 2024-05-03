#include "wheel.h"
#include <QtMath>

Wheel::Wheel(QGraphicsScene *parent) :
    MovingCircle(parent)
{
    // center.setX(x0/2);
    // center.setY(y0/2);
    // this->MovingCircle::setPos(center);
    // this->MovingCircle::setTransformOriginPoint(center);
    // step = x0/10;
}

Wheel::~Wheel(){}

void Wheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if(isrotated){
        painter->rotate(45);
    }
    painter->setPen(QPen(QColor(0,0,0,0)));
    painter->setBrush(QBrush(QColor(138,46,225)));

    painter->setBrush(QBrush(QColor(138,46,255)));

    QPainterPath *holes = new QPainterPath();
    holes->setFillRule(Qt::FillRule::OddEvenFill);


    QPointF *curCenter = new QPointF();
    for(int i = 0; i < 4; ++i){
        curCenter->setX(50*qCos(qDegreesToRadians((double)(90*i))));
        curCenter->setY(-50*qSin(qDegreesToRadians((double)(90*i))));
        holes->moveTo(*curCenter);
        holes->arcTo(curCenter->x()-50, curCenter->y()-50, 100, 100, -45+90*i,90);
        holes->closeSubpath();
    }




    QPainterPath *tire = new QPainterPath();
    tire->setFillRule(Qt::FillRule::OddEvenFill);
    QPainterPath *disc = new QPainterPath();
    disc->setFillRule(Qt::FillRule::OddEvenFill);



    tire->addEllipse(-150,-150, 300,300);
    tire->closeSubpath();
    tire->connectPath(*holes);
    painter->setBrush(QBrush(QColor(0,0,0)));
    painter->drawPath(*tire);

    disc->addEllipse(-110,-110, 220,220);
    disc->closeSubpath();
    disc->connectPath(*holes);
    painter->setBrush(QBrush(QColor(100,100,100)));
    painter->drawPath(*disc);
}
