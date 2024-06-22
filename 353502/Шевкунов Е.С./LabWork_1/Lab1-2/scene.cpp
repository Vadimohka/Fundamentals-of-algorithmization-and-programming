#include "scene.h"

Scene::Scene(qreal a, qreal b, qreal c, qreal d, QWidget *parent) : QGraphicsScene(a, b, c, d, parent)
{

}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMousePressEvent(event);
    QGraphicsScene::mousePressEvent(event);
}


void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMouseReleaseEvent(event);
    QGraphicsScene::mouseReleaseEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMouseMoveEvent(event);
    QGraphicsScene::mouseMoveEvent(event);
}

void Scene::keyPressEvent(QKeyEvent* event)
{
    emit signalKeyPressEvent(event);
    //QWidget::keyPressEvent(event);
}
