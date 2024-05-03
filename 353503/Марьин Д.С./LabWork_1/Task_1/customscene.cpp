#include "customscene.h"

CustomScene::CustomScene(QObject *parent)
    : QGraphicsScene{parent}
{
    mousePos.setX(0);
    mousePos.setY(0);
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    mousePos.setX(event->scenePos().x());
    mousePos.setY(event->scenePos().y());
    qDebug()<<(QString("X :%1. Y:%2").arg(mousePos.x()).arg(mousePos.y()));
    emit signalTargetCoordinate(mousePos);
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if(event->button() == Qt::LeftButton)
        emit signalBlink();
    if(event->button() == Qt::RightButton)
        emit signalTransform();
}
