#include "scene.h"

Scene::Scene(qreal x, qreal y, qreal a, qreal b){}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMousePressEvent(event);
    QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMouseMoveEvent(event);
    QGraphicsScene::mouseMoveEvent(event);
}
void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMouseReleaseEvent(event);
    QGraphicsScene::mouseReleaseEvent(event);
}

void Scene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    emit signalWheelRotationEvent(event);
    QGraphicsScene::wheelEvent(event);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    emit signalKeyPressEvent(event);
    QGraphicsScene::keyPressEvent(event);
}

