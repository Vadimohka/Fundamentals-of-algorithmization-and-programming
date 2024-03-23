#include "customscene.h"

CustomScene::CustomScene(QObject *parent)
    : QGraphicsScene(parent)
{
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_mouseHeld = true;
        emit mousePressed(event->scenePos());
    }

    QGraphicsScene::mousePressEvent(event);
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    m_mouseHeld = false;
    QGraphicsScene::mouseReleaseEvent(event);
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (m_mouseHeld) {
        emit mousePressed(event->scenePos());
    }
    QGraphicsScene::mouseMoveEvent(event);
}
