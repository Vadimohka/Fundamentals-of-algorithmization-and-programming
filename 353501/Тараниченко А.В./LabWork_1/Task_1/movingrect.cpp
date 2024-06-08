#include "movingrect.h"

movingrect::movingrect() {
    QGraphicsRectItem *Rect = new QGraphicsRectItem(-250, -50, 400, 100, this);
    Rect->setBrush(Qt::darkMagenta);
    setFlag(QGraphicsItem::ItemIsMovable);
}

void movingrect::moveLeft(){
    setPos(x() - 10, y());
}

void movingrect::moveRight(){
    setPos(x() + 10, y());
}

void movingrect::moveUp(){
    setPos(x(), y() - 10);
}

void movingrect::moveDown(){
    setPos(x(), y() + 10);
}
