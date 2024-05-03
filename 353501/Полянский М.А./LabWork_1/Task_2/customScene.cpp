#include "customScene.h"

customScene::customScene(QObject* parent) : QGraphicsScene(parent) , holdmouse(false){}

void customScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        holdmouse = true;
        emit mousePressed(event->scenePos());
    }

    QGraphicsScene::mousePressEvent(event);
}

void customScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        holdmouse = false;
    }

    QGraphicsScene::mouseReleaseEvent(event);
}

void customScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (holdmouse)
    {
        emit mousePressed(event->scenePos());
    }

    QGraphicsScene::mouseMoveEvent(event);
}
\
