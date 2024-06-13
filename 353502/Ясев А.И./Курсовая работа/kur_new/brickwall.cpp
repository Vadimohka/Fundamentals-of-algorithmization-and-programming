#include "brickwall.h"

BrickWall::BrickWall(qint8 x, qint8 y, QGraphicsObject *parent) : SteelWall(x, y, parent)
{
    QPixmap map(QDir::current().filePath("resources/brick.jpg"));
    this->pixmap = map;
}

BrickWall::~BrickWall()
{

}

void BrickWall::takeDamage(qint8 damage)
{
    hp-=damage;
    if(hp <= 0){
        emit onDeath(this->getCell());
        this->deleteLater();
    }
}

