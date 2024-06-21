#include "canvas.h"

constexpr int POINT_DIAMETER = 10;

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event->scenePos().x(),
               event->scenePos().y(),
               POINT_DIAMETER, POINT_DIAMETER,
               QPen(Qt::NoPen), QBrush(Qt::red));
    point = event->scenePos();
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(point.x(),
            point.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::red, POINT_DIAMETER));
    point = event->scenePos();
}
