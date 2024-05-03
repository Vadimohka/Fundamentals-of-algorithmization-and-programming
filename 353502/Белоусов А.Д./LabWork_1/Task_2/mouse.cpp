#include "mouse.h"

mouseCatcher::mouseCatcher(paintScene *sceneToGetMouse)
    : sceneToGetMouse(sceneToGetMouse)
{
    connect(sceneToGetMouse, &paintScene::mouseEventOccured, this, &mouseCatcher::processMouseEvent);
}

void mouseCatcher::processMouseEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->type() == QGraphicsSceneMouseEvent::GraphicsSceneMouseMove)
    {
        if (previous.x() == INT_MIN && previous.y() == INT_MIN)
        {
            previous.setX(event->scenePos().x());
            previous.setY(event->scenePos().y());
        }

        emit mouseDragged(previous.x(), previous.y(), event->scenePos().x(), event->scenePos().y());
    }
    else if (event->type() == QGraphicsSceneMouseEvent::GraphicsSceneMousePress)
    {
        emit mouseClicked(event->scenePos().x(), event->scenePos().y());
    }
    else if (event->type() == QGraphicsSceneMouseEvent::GraphicsSceneMouseRelease)
    {
        previous.setX(INT_MIN);
        previous.setY(INT_MIN);
    }

    previous.setX(event->scenePos().x());
    previous.setY(event->scenePos().y());
}
