#include "cinema.h"

Cinema::Cinema(QObject *parent)
    : QGraphicsScene{parent}
{}

Cinema::~Cinema(){

}

void Cinema::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    if(event->buttons() == Qt::LeftButton)
        emit signalMouseDoubleLeftClickEvent(event);
}

void Cinema::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::LeftButton)
        emit signalMouseReleaseLeftButtonEvent(event);
}

void Cinema::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(event->buttons() == Qt::LeftButton)
        emit signalMouseMoveEvent(event);
}

void Cinema::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->buttons() == Qt::LeftButton)
        emit signalMousePressLeftButtonEvent(event);
}
