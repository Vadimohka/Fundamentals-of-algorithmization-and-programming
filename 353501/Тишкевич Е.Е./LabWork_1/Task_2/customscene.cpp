#include "customscene.h"

CustomScene::CustomScene(QObject *parent){}

CustomScene::~CustomScene(){}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit mousePressed(event->scenePos());

    QGraphicsScene::mouseMoveEvent(event);
}
