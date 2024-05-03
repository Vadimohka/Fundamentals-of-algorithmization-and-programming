#include "line.h"

void line::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event -> scenePos().x() - 5, event->scenePos().y() - 5, 7, 7, QPen(Qt::NoPen), QBrush(Qt::green));
    point = event -> scenePos();
}

void line::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(point.x(), point.y(), event -> scenePos().x(), event -> scenePos().y(), QPen(Qt::green, 7, Qt::SolidLine, Qt::RoundCap));
    point = event -> scenePos();
}
