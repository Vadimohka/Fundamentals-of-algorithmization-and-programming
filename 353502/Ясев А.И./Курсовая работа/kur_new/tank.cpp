#include "tank.h"


Tank::Tank(qint8 x, qint8 y, QGraphicsObject *parent) : Square(x,y, parent) {
    reloadTimer = new QTimer(this);
    reloadTimer->setSingleShot(true);
    reloadTimer->setInterval(1000);
    connect(reloadTimer, &QTimer::timeout, this, &Tank::shootTimerTimeout);
    hp = maxhp;
    this->direction = Direction::NONE;
}
Tank::~Tank(){}

void Tank::shootTimerTimeout(){
    this->isShootEnabled=true;
}

Square::Direction Tank::getDirection(){
    return this->direction;
}

QRectF Tank::boundingRect() const
{
    return QRectF(-15,-15,30,30);
}

void Tank::shoot(bool isDD){
    if(isShootEnabled){
        Bullet *bullet = new Bullet(this->x(), this->y(), this->direction, isDD);
        scene()->addItem(bullet);
        isShootEnabled = false;
        reloadTimer->start();
    }
}

void Tank::rotate(Direction direction){
    this->direction = direction;
    update();
}
void Tank::move(qint64 stepSize){
    if (direction == NONE){
        return;
    }
    double radians = qDegreesToRadians((double)direction);
    this->setPos(this->x() + stepSize*qCos(radians), this->y() + stepSize*qSin(radians));
    if(qRound64(x())>(800-boundingRect().width()/2)){
        this->setPos(this->x() - stepSize, this->y());
    }
    if(qRound64(x())<boundingRect().width()/2){
        this->setPos(this->x() + stepSize, this->y());
    }
    if(qRound64(y())>(800-boundingRect().height()/2)){
        this->setPos(this->x(), this->y() - stepSize);
    }
    if(qRound64(y())<boundingRect().height()/2){
        this->setPos(this->x(), this->y() + stepSize);
    }
}

void Tank::takeDamage(qint8 damage){
    this->hp -= damage;
    if (hp <= 0){
        deleteLater();
    }
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    this->setRotation(direction);
    this->Square::paint(painter, option, widget);
}
