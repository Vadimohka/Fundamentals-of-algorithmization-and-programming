#include "myscene.h"
#include "QDebug"
#include "QGraphicsSceneMouseEvent"

MyScene::MyScene(QObject *parent)
    : QGraphicsScene{parent}
{

}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit MyMouseMoveEvent(event);
}
