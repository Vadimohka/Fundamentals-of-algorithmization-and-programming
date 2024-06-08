#include "snake.h"
#include "Pepper.h"
#include "ItemsContainer.h"
#include <QDebug>

QGraphicsScene *sc;

Snake::Snake(QGraphicsScene *scene, float StartPosX, float StartPosY, QString n,int col) {
    name = n;
    alive = true;
    lenght = 8;
    speed = 3;
    direction = "up";
    headImagePath = ":/images/snakeUnit" + QString::number(col) + "Head.png";
    bodyImagePath = ":/images/snakeUnit" + QString::number(col) + ".png";
    for(int i = 0; i < lenght; ++i) {
        SnakePart *snakepart = new SnakePart(name);
        if (i == 0) {
            snakepart->setPixmap(QPixmap(headImagePath));
            snakepart->setTransformOriginPoint(snakepart->pixmap().width() / 2, snakepart->pixmap().height() / 2);
        } else {
            snakepart->setPixmap(QPixmap(bodyImagePath));
            snakepart->setZValue(-1 - (i % 100));
        }
        snakepart->setPos(StartPosX, StartPosY - 8 * (lenght - i));
        scene->addItem(snakepart);
        body.push_back(snakepart);
    }
    name_label = new QGraphicsTextItem();
    name_label->setFont(QFont("calibri", 9));
    name_label->setPlainText(name);
    name_label->setDefaultTextColor(Qt::white);
    name_label->setPos(body[0]->pos().x() + 10, body[0]->pos().y() + 10);
    scene->addItem(name_label);
    PepperActiveTimer = new QTimer();
    connect(PepperActiveTimer, &QTimer::timeout, this, &Snake::PepperDisactive);
    SnakeMoveTimer = new QTimer();
    connect(SnakeMoveTimer, &QTimer::timeout, this, &Snake::move);
    SnakeMoveTimer->start(20);
}

void Snake::move() {
    //bool not_in_playground = (body[0]->x() >= 4000 || body[0]->x() <= 0 || body[0]->y() >= 4000 || body[0]->y() <= 0);
    //if (not_in_playground) destroySnake();
    if (alive) {
        for (int i = body.length() - 1; i >= 0; --i) {
            if (!alive) break;
            if (i != 0) {
                body[i]->setY(body[i - 1]->y());
                body[i]->setX(body[i - 1]->x());
                continue;
            }
            if (direction == "up") {
                body[i]->setY(body[i]->y() - speed);
            }
            if (direction == "down") {
                body[i]->setY(body[i]->y() + speed);
            }
            if (direction == "right") {
                body[i]->setX(body[i]->x() + speed);
            }
            if (direction == "left") {
                body[i]->setX(body[i]->x() - speed);
            }
        }
        name_label->setPos(body[0]->pos().x() + 10, body[0]->pos().y() + 10);
        QList<QGraphicsItem *> colliding_items = body[0]->collidingItems();
        for (int i = 0; i < colliding_items.size(); i++) {
            if (typeid(*(colliding_items[i])) == typeid(Food)) {
                body[0]->scene()->removeItem(colliding_items[i]);
                ItemsContainer::allFoods.removeOne(colliding_items[i]);
                delete colliding_items[i];
                SnakePart *newBodyPart = new SnakePart(name);
                newBodyPart->setPixmap(QPixmap(bodyImagePath));
                newBodyPart->setPos(-1212121, -100121);
                body[0]->scene()->addItem(newBodyPart);
                body.append(newBodyPart);
                lenght++;
            } else if (typeid(*(colliding_items[i])) == typeid(Pepper)) {
                body[i]->scene()->removeItem(colliding_items[i]);
                ItemsContainer::allPeppers.removeOne(colliding_items[i]);
                delete colliding_items[i];
                SnakeMoveTimer->start(5);
                speed = 4;
                PepperActiveTimer->start(4000);
            } else if (typeid(*(colliding_items[i])) == typeid(SnakePart) &&
                       ((SnakePart *) colliding_items[i])->snakeName != name) {
                destroySnake();
                break;
            } else if (typeid(*(colliding_items[i])) == typeid(Stone)) {
                body[0]->scene()->removeItem(colliding_items[i]);
                ItemsContainer::allStones.removeOne(colliding_items[i]);
                delete colliding_items[i];
                destroySnake();
                break;
            }
        }
        emit moveSignal();
    }else {
        emit gameOverSignal();
    }
}

void Snake::PepperDisactive() {
    SnakeMoveTimer->start(20);
    speed = 3;
}

void Snake::setDirection(QString dir) {
    if (dir == "right" && direction != "left") {
        direction = "right";
        body[0]->setRotation(0);
        body[0]->setRotation(90);
    } else if (dir == "left" && direction != "right") {
        direction = "left";
        body[0]->setRotation(0);
        body[0]->setRotation(-90);
    } else if (dir == "up" && direction != "down") {
        direction = "up";
        body[0]->setRotation(0);
    } else if (dir == "down" && direction != "up") {
        direction = "down";
        body[0]->setRotation(0);
        body[0]->setRotation(180);
    }
}

void Snake::destroySnake() {
    body[0]->scene()->removeItem(name_label);
    for (int i = 0; i < body.size(); ++i) {
        Food *food = new Food(body[i]->x(), body[i]->y());
        body[i]->scene()->addItem(food);
        ItemsContainer::allFoods.push_back(food);
        body[i]->scene()->removeItem(body[i]);
    }
    delete name_label;
    alive = false;
}

QString Snake::getDirection() {
    return direction;

}

void Snake::setSpeed(int s) {
    speed = s;
}

int Snake::getSpeed() {
    return speed;
}

QPointF Snake::getHeadPos() {
    return body[0]->pos();
}

void Snake::pause_snake() {
    SnakeMoveTimer->stop();
    if(PepperActiveTimer->isActive()) {
        pepperTimerRemainingTime = PepperActiveTimer->remainingTime();
        PepperActiveTimer->stop();
    }
}

void Snake::continue_snake() {
    SnakeMoveTimer->start(20);
    if(pepperTimerRemainingTime > 0) {
        PepperActiveTimer->start(pepperTimerRemainingTime);
    }
}
QString Snake::getName(){
    return name;
}
int Snake::getLength(){
    return lenght;
}