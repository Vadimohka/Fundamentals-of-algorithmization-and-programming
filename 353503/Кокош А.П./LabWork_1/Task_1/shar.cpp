#include "shar.h"

Shar::Shar()
    : Ellips()
{
    ellipse = new QGraphicsEllipseItem(-30, -40, 60, 80, this);
    ellipse->setBrush(Qt::blue);
    shnur = new QGraphicsLineItem(0, 40, 0, 130, this);
}

Shar::~Shar() {}

QRectF Shar::boundingRect() const
{
    return QRectF(-30, -40, 60, 130);
}
