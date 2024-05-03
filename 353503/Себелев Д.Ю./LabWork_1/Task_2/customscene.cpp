#include "customscene.h"

CustomScene::CustomScene(QObject *parent)
    : QGraphicsScene{parent}
{}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
        previous_pos = event->scenePos();

        QPointF cursor_pos = event->scenePos();
        emit leftMousePressed(cursor_pos);
    }
    else if (event->button() == Qt::RightButton)
    {
        emit rightMousePressed(event);
    }
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    last_pos = event->scenePos();
    emit mouseMoved(previous_pos, last_pos);
    previous_pos = last_pos;

    QGraphicsScene::mouseMoveEvent(event);
}

void CustomScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        emit deleteItem();
    }
}

