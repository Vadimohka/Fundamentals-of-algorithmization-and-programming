#include "figure.h"
#include <iostream>
#include <QPainter>
#include <QPolygon>

Figure::Figure(QGraphicsItem *parent2) : QGraphicsItem(parent2) {
    setCenter = false;
    setFlag(QGraphicsItem::ItemIsFocusable, true);
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!setCenter) {
        centerX = event->scenePos().x();
        centerY = event->scenePos().y();
        setCenter = true;
    }
    else {
        setTransformOriginPoint(event->pos());
    }
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    mouseX = event->scenePos().x() - centerX;
    mouseY = event->scenePos().y() - centerY;

    update();
}

void Figure::keyPressEvent(QKeyEvent *event) {
    int step = 10;
    switch (event->key()){
    case Qt::Key_Left:
        this->moveBy(-step, 0);
        break;
    case Qt::Key_Right:
        this->moveBy(step, 0);
        break;
    case Qt::Key_Up:
        this->moveBy(0, -step);
        break;
    case Qt::Key_Down:
        this->moveBy(0, step);
        break;
    case Qt::Key_R:
        rotate(10);
        break;
    }
}

void Figure::rotate(double angle) {
    setRotation(rotation() + angle);
}
