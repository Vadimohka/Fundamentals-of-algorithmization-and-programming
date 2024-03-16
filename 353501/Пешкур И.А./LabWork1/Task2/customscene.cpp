#include "customscene.h"

CustomScene::CustomScene(QObject *parent) : QGraphicsScene(parent){}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (mouse->button() == Qt::LeftButton) {

        mouseHeld = true;
        emit mousePressed(mouse->scenePos());

    }

    QGraphicsScene::mousePressEvent( mouse );
}

void CustomScene :: mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse)
{
    if (mouse->button() == Qt::LeftButton)
    {
        mouseHeld = false;
    }

    QGraphicsScene::mouseReleaseEvent( mouse );
}

void CustomScene :: mouseMoveEvent(QGraphicsSceneMouseEvent* mouse)
{
    if ( mouseHeld )
    {
        emit mousePressed( mouse->scenePos() );
    }

    QGraphicsScene::mouseMoveEvent( mouse );
}
