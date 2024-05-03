#include "canva.h"
#include "QDebug"
#include "QGraphicsSceneMouseEvent"

Canva::Canva(QObject *parent)
        : QGraphicsScene{parent} {

}

void Canva::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit signalMouseDoubleLeftClickEvent(event);
    }
}

void Canva::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit signalMousePressLeftButtonEvent(event);
    }
    else if (event->button() == Qt::RightButton) {
        emit signalMousePressRightButtonEvent(event);
    }
}

void Canva::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit signalMouseReleaseLeftButtonEvent(event);
    }
    if (event->button() == Qt::LeftButton) {
        emit signalMouseReleaseRightButtonEvent(event);
    }
}

void Canva::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

    if (event->buttons() & Qt::LeftButton) {
        emit signalMouseMoveEvent(event);
    }
}


