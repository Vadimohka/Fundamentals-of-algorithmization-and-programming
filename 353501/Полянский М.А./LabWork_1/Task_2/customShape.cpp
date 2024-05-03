#include "customShape.h"

customShape::customShape(){}
void customShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setPen(QPen(Qt::white, 2));
    QPointF rotationCenter;
    rotationCenter = (QPointF(0 + moveX+ rotatecenterx, 0 + moveY+rotatecentery));
    if(!center_connected) {
        rotationCenter = (QPointF(0 + moveX, 0 + moveY));
    }
    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(rotationCenter);
    painter->rotate(rotate_angle);
    painter->translate(-rotationCenter);
    for (int i = 0; i < points.size();++i) {
        painter->drawEllipse(points[i] * m_scaleFactor + QPointF(moveX+rotatecenterx,moveY+rotatecentery),1,1);
    }
    painter->drawEllipse(rotationCenter,1,1);
}

void customShape::addPoint(const QPointF& point)
{
    points.push_back(point);
}
