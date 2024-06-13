#include "steelwall.h"

SteelWall::SteelWall(qint8 x, qint8 y, QGraphicsObject *parent) : Square(x,y, parent){
    QPixmap map(QDir::current().filePath("resources/steel.jpg"));
    this->pixmap = map;
    this->x = x;
    this->y = y;
}

