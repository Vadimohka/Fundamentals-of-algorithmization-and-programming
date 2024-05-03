#include "customscene.h"


CustomScene::CustomScene(QObject *parent):QGraphicsScene(parent)
{

}

CustomScene::~CustomScene()
{

}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event->scenePos().x(), event->scenePos().y(), 10, 10, QPen(Qt::NoPen),QBrush(Qt::red));
    point = event->scenePos();
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(point.x(), point.y(), event->scenePos().x(), event->scenePos().y(), QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    point = event->scenePos();
}

