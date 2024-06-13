#include "brickwall.h"
#include "bullet.h"
#include "player.h"
#include "steelwall.h"
#include "tank.h"

Bullet::Bullet(qreal x0, qreal y0, Direction direction, bool isDD, QGraphicsObject *parent) : Square(x0, y0, parent) {
    double radians = qDegreesToRadians((double)direction);
    this->setRotation(direction);
    this->setPos(x0 + 22*qCos(radians), y0 + 22*qSin(radians));

    this->direction = direction;
    this->isDD = isDD;
    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Bullet::move);
    moveTimer->start(10);
}

Bullet::~Bullet(){}

QRectF Bullet::boundingRect() const{
    return QRectF(-2,-1,4,2);
}
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(Qt::white));
    painter->setPen(QPen(Qt::white));
    painter->drawRect(this->boundingRect());
    update();
}
void Bullet::move(){
    double radians = qDegreesToRadians((double)direction);
    this->setPos(this->x() + 15*qCos(radians), this->y() + 15*qSin(radians));
    foreach(auto item, scene()->collidingItems(this)){
        if(Player *player = dynamic_cast<Player*>(item)){
            if(!player->isInGhostForm()){
                if(isDD){
                    player->takeDamage(2);
                }
                else{
                player->takeDamage(1);
                deleteLater();
                }
            }
        }
        else if(Tank *tank = dynamic_cast<Tank*>(item)){
            if(isDD){
                tank->takeDamage(2);
            }
            else{
                tank->takeDamage(1);
                deleteLater();
            }
        }
        else if(BrickWall *wall = dynamic_cast<BrickWall*>(item)){
            if(isDD){
                wall->takeDamage(2);
            }
            else{
                wall->takeDamage(1);
                deleteLater();
            }
        }
        else if(SteelWall *wall = dynamic_cast<SteelWall*>(item)){
            if(!isDD){
            deleteLater();
            }
        }
    }
    if(this->x()>810){
        deleteLater();
    }
    if(this->x()<-10){
        deleteLater();
    }
    if(this->y()>810){
        deleteLater();
    }
    if(this->y()<-10){
        deleteLater();
    }
}
