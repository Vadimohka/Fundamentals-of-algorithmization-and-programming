#include "customview.h"

CustomView::CustomView(QObject *parent)
    : QGraphicsScene{parent}
{
}

// void CustomView::mousePressEvent(QGraphicsSceneMouseEvent *event)
// {
//     if (event->button() == Qt::LeftButton)
//     {
//         QPointF cursor_pos = event->scenePos();
//         emit leftMousePressed(cursor_pos);
//     }
// }
