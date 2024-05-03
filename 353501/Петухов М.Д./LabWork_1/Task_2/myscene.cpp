#include "myscene.h"

CustomScene::CustomScene(QObject *parent) : QGraphicsScene(parent)
{
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit mousePressed(event->scenePos());
    }

    QGraphicsScene::mousePressEvent(event);
}
