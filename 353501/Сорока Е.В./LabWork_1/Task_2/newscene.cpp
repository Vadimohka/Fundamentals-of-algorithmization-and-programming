#include "newscene.h"

NewScene::NewScene(QObject *parent) : QGraphicsScene(parent){}

void NewScene::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (mouse->button() == Qt::LeftButton) {

        mouseHeld = true;
        emit mousePressed(mouse->scenePos());

    }

    QGraphicsScene::mousePressEvent( mouse );
}

void NewScene :: mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse)
{
    if (mouse->button() == Qt::LeftButton)
    {
        mouseHeld = false;
    }

    QGraphicsScene::mouseReleaseEvent( mouse );
}

void NewScene :: mouseMoveEvent(QGraphicsSceneMouseEvent* mouse)
{
    if ( mouseHeld )
    {
        emit mousePressed( mouse->scenePos() );
    }

    QGraphicsScene::mouseMoveEvent( mouse );
}
