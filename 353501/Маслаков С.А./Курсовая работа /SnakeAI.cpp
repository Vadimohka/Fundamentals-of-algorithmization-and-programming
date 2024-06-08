#include "Pepper.h"
#include "SnakeAI.h"
#include "ItemsContainer.h"
#include <QDebug>

QGraphicsScene *s;

SnakeAI::SnakeAI(QGraphicsScene *scene, float StartPosX, float StartPosY, QString n) {
    PepperEffectActive = false;
    name = n;
    alive = true;
    lenght = 8;
    speed = 3;
    color = random() % 10 + 1;
    direction = "up";
    boundary = new QGraphicsEllipseItem(0, 0, 50, 50);
    boundary->setPen(QPen(Qt::transparent));
    boundary->setZValue(-1);
    scene->addItem(boundary);
    for (int i = 0; i < lenght; ++i) {
        SnakePart *snakepart = new SnakePart(name);
        if (i == 0) {
            snakepart->setPixmap(QPixmap(":/images/snakeUnit" + QString::number(color) + "Head.png"));
            snakepart->setTransformOriginPoint(snakepart->pixmap().width() / 2, snakepart->pixmap().height() / 2);
        } else {
            snakepart->setPixmap(
                    QPixmap(":/images/snakeUnit" + QString::number(color) + ".png"));
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
    boundary = new QGraphicsEllipseItem(0, 0, 70, 70);
    boundary->setPen(QPen(Qt::transparent));
    boundary->setZValue(-1);
    scene->addItem(boundary);
    boundary->setX(body[0]->x() - boundary->rect().width() / 2);
    boundary->setY(body[0]->y() - boundary->rect().height() / 2);
    PepperAIActiveTimer = new QTimer();
    connect(PepperAIActiveTimer, &QTimer::timeout, this, &SnakeAI::PepperDisactive);
    SnakeAIMoveTimer = new QTimer();
    connect(SnakeAIMoveTimer, &QTimer::timeout, this, &SnakeAI::move);
    if (alive) SnakeAIMoveTimer->start(20);
}
void SnakeAI::calculateClosestWay() {
    long double dx;
    long double dy;
    long double food_min_distance = std::numeric_limits<long double>::max();  // Initialize min_distance with a large value
    long double pepper_min_distance = std::numeric_limits<long double>::max();  // Initialize min_distance with a large value
    QPointF snakesHeadPosition = body[0]->pos();
    QPointF closestFoodPosition = QPointF(0, 0);
    QPointF closestPepperPosition = QPointF(0, 0);

    for (int i = 0; i < ItemsContainer::allFoods.size(); ++i) {
        long long x = abs(snakesHeadPosition.rx() - ItemsContainer::allFoods[i]->x());
        long double y = abs(snakesHeadPosition.ry() - ItemsContainer::allFoods[i]->y());
        long double distance = std::sqrt(x * x + y * y);

        if (distance < food_min_distance) {
            food_min_distance = distance;
            //qDebug() << i << ItemsContainer::allFoods[i]->pos();
            closestFoodPosition = ItemsContainer::allFoods[i]->pos();
        }
    }
    for (int i = 0; i < ItemsContainer::allPeppers.size(); ++i) {
        long long x = abs(snakesHeadPosition.rx() - ItemsContainer::allPeppers[i]->x());
        long double y = abs(snakesHeadPosition.ry() - ItemsContainer::allPeppers[i]->y());
        long double distance = std::sqrt(x * x + y * y);
        if (distance < pepper_min_distance) {
            pepper_min_distance = distance;
            closestPepperPosition = ItemsContainer::allPeppers[i]->pos();
        }
    }
    if (pepper_min_distance < food_min_distance) {
        dx = closestPepperPosition.rx() - snakesHeadPosition.rx();
        dy = closestPepperPosition.ry() - snakesHeadPosition.ry();
    } else {
        dx = closestFoodPosition.rx() - snakesHeadPosition.rx();
        dy = closestFoodPosition.ry() - snakesHeadPosition.ry();
    }
    if (dx == 0 && dy != 0) {
        if (dy < 0) {
            setDirection("up");
        } else {
            setDirection("down");
        }
    } else if (dy == 0 && dx != 0) {
        if (dx < 0) {
            setDirection("left");
        } else {
            setDirection("right");
        }
    } else {
        if (std::abs(dx) >= std::abs(dy)) {
            if (dx > 0) {
                setDirection("right");
            } else {
                setDirection("left");
            }
        } else {
            if (dy > 0) {
                setDirection("down");
            } else {
                setDirection("up");
            }
        }
    }
}
void SnakeAI::move() {
    calculateClosestWay();
    for (int i = body.length() - 1; i >= 0; --i) {
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
    boundary->setX(body[0]->x() - boundary->rect().width() / 2);
    boundary->setY(body[0]->y() - boundary->rect().height() / 2);
    CheckCollision();
}

void SnakeAI::PepperDisactive() {
    speed = 3;
    SnakeAIMoveTimer->start(20);
}

void SnakeAI::setDirection(QString dir) {
    if (dir == "right") {
        direction = "right";
        body[0]->setRotation(0);
        body[0]->setRotation(90);
    } else if (dir == "left") {
        direction = "left";
        body[0]->setRotation(0);
        body[0]->setRotation(-90);
    } else if (dir == "up") {
        direction = "up";
        body[0]->setRotation(0);
    } else if (dir == "down") {
        direction = "down";
        body[0]->setRotation(0);
        body[0]->setRotation(180);
    }
}

void SnakeAI::destroySnake() {
    alive = false;
    body[0]->scene()->removeItem(name_label);
    for (int i = 0; i < body.size(); ++i) {
        Food *food = new Food(body[i]->x(), body[i]->y());
        body[i]->scene()->addItem(food);
        ItemsContainer::allFoods.push_back(food);
        body[i]->scene()->removeItem(body[i]);
    }
    ItemsContainer::allSnakesAI.removeOne(this);
    emit addNewSnakeAiSignal();
}

QString SnakeAI::getDirection() {
    return direction;

}

void SnakeAI::setSpeed(int s) {
    speed = s;
}

int SnakeAI::getSpeed() {
    return speed;
}

void SnakeAI::CheckCollision() {
    QList<QGraphicsItem *> colliding_items = body[0]->collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(Food)) {
            body[0]->scene()->removeItem(colliding_items[i]);
            ItemsContainer::allFoods.removeOne(colliding_items[i]);
            delete colliding_items[i];

            SnakePart *newBodyPart = new SnakePart(name);
            newBodyPart->setPixmap(
                    QPixmap(":/images/snakeUnit" + QString::number(color) + ".png"));
            if (direction == "right" || direction == "left") {
                newBodyPart->setPos(body[body.length() - 1]->pos().rx() - 8, body[body.length() - 1]->pos().ry());
            }
            newBodyPart->setPos(body[body.length() - 1]->pos().rx(), body[body.length() - 1]->pos().ry() - 8);
            body[0]->scene()->addItem(newBodyPart);
            body.append(newBodyPart);
            lenght++;
        } else if (typeid(*(colliding_items[i])) == typeid(Pepper)) {
            body[0]->scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            ItemsContainer::allPeppers.removeOne(colliding_items[i]);
            speed = 4;
            SnakeAIMoveTimer->start(5);
            PepperAIActiveTimer->start(4000);
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
  /*  QList<QGraphicsItem *> collidingBoundaryItems = boundary->collidingItems();
    for (int i = 0; i < collidingBoundaryItems.size(); ++i) {
        bool SnakePartsCollides = (typeid(*(collidingBoundaryItems[i])) == typeid(SnakePart) && (((SnakePart *) collidingBoundaryItems[i])->snakeName != name));
        bool CollidesWithStone = (typeid(*(collidingBoundaryItems[i])) == typeid(Stone));
        //bool CollidesWithMainSnake = (((SnakePart *) collidingBoundaryItems[i])->snakeName == "main");
        if (SnakePartsCollides && CollidesWithStone) {
            setDirection(getSafeDirection());
            break;
        }
    }*/
}

QPointF SnakeAI::getAIHeadPos() {
    return body[0]->pos();
}

void SnakeAI::pause_snakeAI() {
    SnakeAIMoveTimer->stop();
    PepperAIActiveTimer->stop();
    pepperAITimerRemainingTime = PepperAIActiveTimer->remainingTime();
}

void SnakeAI::continue_snakeAI() {
    SnakeAIMoveTimer->start(20);
    PepperAIActiveTimer->start(pepperAITimerRemainingTime);
}

QString SnakeAI::getName() {
    return name;
}

int SnakeAI::getLength() {
    return lenght;
}

QString SnakeAI::getSafeDirection() {

    QString currentDirection = getDirection();

    if (isMoveSafe(getAIHeadPos(), currentDirection)) {
        return currentDirection;
    }

    if (currentDirection == "right" || currentDirection == "left") {
        if (isMoveSafe(getAIHeadPos(), "up")) {
            return "up";
        } else return "down";
    } else if (currentDirection == "up" || currentDirection == "down") {
        if (isMoveSafe(getAIHeadPos(), "right")) {
            return "right";
        } else return "left";
    }
}

bool SnakeAI::isMoveSafe(QPointF headPos, QString dir) {

    QPointF newPos;
    if (dir == "right") {
        qreal x = headPos.x() + speed;
        newPos = {x, headPos.y()};
    } else if (dir == "left") {
        qreal x = headPos.x() - speed;
        newPos = {x, headPos.y()};
    } else if (dir == "up") {
        qreal y = headPos.y() - speed;
        newPos = {headPos.x(), y};
    } else if (dir == "down") {
        qreal y = headPos.y() + speed;
        newPos = {headPos.x(), y};
    }

    // Check for collision with other snakes or stones
    for (Stone *stone : ItemsContainer::allStones) {
        if (stone->pos() == newPos) {
            return false;
        }
    }
    for (SnakeAI *snakeAI : ItemsContainer::allSnakesAI) {
        for (SnakePart* part : snakeAI->body) {
            if (part->pos() == newPos) {
                return false;
            }
        }
    }
    return true;
}
