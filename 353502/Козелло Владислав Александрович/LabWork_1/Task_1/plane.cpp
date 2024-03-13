#include "plane.h"

Plane::Plane()
{

}

Plane::~Plane()
{

}

void Plane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);Q_UNUSED(widget);
    this->movingRect::paint(painter, option, widget);

    painter->setBackgroundMode(Qt::BGMode::OpaqueMode);
    QBrush brush(Qt::blue);
    painter->setBrush(brush);

    const QPointF points[3] =
        {
            QPointF(100,50),
            QPointF(130,50),
            QPointF(80,0)
        };
    painter->drawPolygon(points, 3);

    if(shassi)
    {
        brush.setColor(Qt::lightGray);
        painter->setBrush(brush);

        painter->drawRect(120, 75, 5, 20);
        painter->drawEllipse(115, 85, 20, 20);
        painter->drawEllipse(110, 85, 20, 20);

        painter->drawRect(230, 75, 5, 20);
        painter->drawEllipse(225, 85, 20, 20);
        painter->drawEllipse(220, 85, 20, 20);

        brush.setColor(Qt::blue);
        painter->setBrush(brush);
    }

    const QPointF points1[3] =
        {
            QPointF(150,75),
            QPointF(180,75),
            QPointF(100,120)
        };
    painter->drawPolygon(points1, 3);

    brush.setColor(Qt::black);
    painter->setBrush(brush);
    const QPointF points2[3] =
        {
            QPointF(250,50),
            QPointF(250,75),
            QPointF(300,75)
        };
    painter->drawPolygon(points2, 3);

    brush.setColor(QColor(200,250,250));
    painter->setBrush(brush);
    painter->drawEllipse(110, 55, 10, 15);
    painter->drawEllipse(135, 55, 10, 15);
    painter->drawEllipse(160, 55, 10, 15);
    painter->drawEllipse(185, 55, 10, 15);
    painter->drawEllipse(210, 55, 10, 15);
    painter->drawEllipse(235, 55, 10, 15);

};

void Plane::setShassi()
{
    shassi = true;
}
void Plane::removeShassi()
{
    shassi = false;
}
