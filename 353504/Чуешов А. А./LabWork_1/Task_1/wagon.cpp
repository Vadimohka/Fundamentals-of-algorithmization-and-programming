#include "wagon.h"

Wagon::Wagon(QGraphicsEllipseItem *leftWheel, QGraphicsEllipseItem *rightWheel)
    : leftWheel(leftWheel), rightWheel(rightWheel) {}

void Wagon::keyPressEvent(QKeyEvent *event) {
    int dx;
    if (event->key() == Qt::Key_Left) {
        dx = -10;
    } else if (event->key() == Qt::Key_Right) {
        dx = 10;
    } else {
        QGraphicsItem::keyPressEvent(event);
        return;
    }

    int newX = x() + dx;
    if (newX < 0 || newX + rect().width() > 800) {
        return;
    }

    setPos(newX, y());
    leftWheel->setPos(leftWheel->x() + dx, leftWheel->y());
    rightWheel->setPos(rightWheel->x() + dx, rightWheel->y());
}
