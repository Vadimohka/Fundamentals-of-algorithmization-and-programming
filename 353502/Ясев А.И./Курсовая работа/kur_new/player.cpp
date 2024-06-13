#include "player.h"

Player::Player(qint8 x, qint8 y, QGraphicsObject *parent) : Tank(x, y, parent), currentCell(getCell().x, getCell().y) {
    QPixmap map(QDir::current().filePath("resources/player.png"));
    this->pixmap = map;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::moveTimerTimeout);
    timer->start(10);
    hp = maxhp;
    ghostTimer = new QTimer(this);
    ghostTimer->setSingleShot(true);
    connect(ghostTimer, &QTimer::timeout, this, &Player::ghostTimerTimeout);
}
Player::~Player(){}

void Player::shoot(bool isDD){
    if(isShootEnabled){
        this->Tank::shoot(isDoubleDamage);
        if (isDoubleDamage){
            isDoubleDamage = false;
        }
        isShootEnabled = false;
        reloadTimer->start();
    }
}

void Player::move(qint64 stepSize)
{
    Tank::move(stepSize);
    double radians = qDegreesToRadians((double)direction);
    foreach(auto item, scene()->collidingItems(this)){
        if(Tank *tank = dynamic_cast<Tank*>(item)){
            if (!isGhost)
            this->setPos(this->x() - stepSize*qCos(radians), this->y() - stepSize*qSin(radians));
        }
        else if(SteelWall *wall = dynamic_cast<SteelWall*>(item)){
            if (!isGhost)
            this->setPos(this->x() - stepSize*qCos(radians), this->y() - stepSize*qSin(radians));
        }
        else if(PowerUp *powerup = dynamic_cast<PowerUp*>(item)){
            powerup->deleteLater();
            PowerUp::Type type = powerup->getType();
            if (type == PowerUp::HEAL){
                hp = maxhp;
                emit changePlayerHP(hp);
            }
            else if (type == PowerUp::DOUBLEDAMAGE){
                isDoubleDamage = true;
            }
            else{
                isGhost = true;
                ghostTimer->start(5000);
            }
        }
    }
}

bool Player::isInGhostForm()
{
    return isGhost;
}

void Player::keyPressEvent(QKeyEvent* e){
    if(e->key() == Qt::Key_D){
        this->enableMovement(Square::RIGHT);
    }
    if(e->key() == Qt::Key_S){
        this->enableMovement(Square::DOWN);
    }
    if(e->key() == Qt::Key_A){
        this->enableMovement(Square::LEFT);
    }
    if(e->key() == Qt::Key_W){
        this->enableMovement(Square::UP);
    }
    if(e->key() == Qt::Key_Space){
        this->shoot();
    }
    update();
}

void Player::keyReleaseEvent(QKeyEvent* e){
    Direction direction;
    if(e->key() == Qt::Key_D){
        direction = Square::RIGHT;
    }
    else if(e->key() == Qt::Key_S){
        direction = Square::DOWN;
    }
    else if(e->key() == Qt::Key_A){
        direction = Square::LEFT;
    }
    else if(e->key() == Qt::Key_W){
        direction = Square::UP;
    }
    else {
        return;
    }

    if(this->direction == direction){
        isMoveEnabled = false;
    }
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isGhost){
        painter->setOpacity(0.25);
    }
    else{
        painter->setOpacity(1);
    }
    Tank::paint(painter, option, widget);
}

void Player::enableMovement(Direction direction){
    if (this->direction == direction){
        this->isMoveEnabled = true;
    }
    else {
        this->rotate(direction);
        this->isMoveEnabled = false;
    }
}

void Player::takeDamage(qint8 damage)
{
    Tank::takeDamage(damage);
    emit changePlayerHP(hp);
}

void Player::moveTimerTimeout(){
    if(isMoveEnabled){
    this->move(stepSize);
        if(currentCell != getCell()){
        currentCell = getCell();
        emit updatePos(currentCell);
        }
    }
}

void Player::ghostTimerTimeout()
{
    isGhost = false;
}

