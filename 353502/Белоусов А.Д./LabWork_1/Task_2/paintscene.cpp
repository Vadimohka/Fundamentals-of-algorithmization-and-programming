#include "paintscene.h"

paintScene::paintScene() = default;

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouseEventOccured(event);
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouseEventOccured(event);
}

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouseEventOccured(event);
}
