#include "Enemy.h"
#include "math.h"
#include <QRandomGenerator>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

Enemy::Enemy(QGraphicsItem *target, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;
    steps = 0;
    countForSteps = 0;
    setRotation(angle);
    this->target = target;
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Enemy::slotGameTimer);
    timer->start(15);
}

Enemy::~Enemy()
{

}

QRectF Enemy::boundingRect() const
{
    return QRectF(-40,-50,80,100);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int x1 = QRandomGenerator::global()->generate() % 50 - 24;
    int y1 = QRandomGenerator::global()->generate() % 90 - 45;
    int x2 = x1 + QRandomGenerator::global()->generate() % 10 - 5;
    int y2 = y1 + QRandomGenerator::global()->generate() % 30 - 15;
    int x3 = x2 + QRandomGenerator::global()->generate() % 10 - 5;
    int y3 = y2 + QRandomGenerator::global()->generate() % 20 - 10;
    int x4 = x1;
    int y4 = y1 + QRandomGenerator::global()->generate() % 20 - 10;

    // Рисуем четырехугольник
    painter->setPen(QPen(Qt::black, 2));
    painter->drawLine(x1, y1, x2, y2);
    painter->drawLine(x2, y2, x3, y3);
    painter->drawLine(x3, y3, x4, y4);
    painter->drawLine(x4, y4, x1, y1);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Enemy::slotGameTimer()
{
    QLineF lineToTarget(QPointF(0, 0), mapFromItem(target, 0, 0));
    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    if (lineToTarget.dy() < 0)
        angleToTarget = TwoPi - angleToTarget;
    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

    if (angleToTarget > 0 && angleToTarget < Pi) {
        if(angleToTarget > Pi / 5){
            angle = -15;
        } else if(angleToTarget > Pi / 10){
            angle = -5;
        } else {
            angle = -1;
        }
    } else if (angleToTarget <= TwoPi && angleToTarget > (TwoPi - Pi)) {
        if(angleToTarget < (TwoPi - Pi / 5)){
            angle = 15;
        } else if(angleToTarget < (TwoPi - Pi / 10)){
            angle = 5;
        } else {
            angle = 1;
        }
    } else if(angleToTarget == 0) {
        angle = 0;
    }

    setRotation(rotation() + angle);


    if(lineToTarget.length() >= 40){
        setPos(mapToParent(0, -(qrand() % ((4 + 1) - 1) + 1)));
        countForSteps++;
        if(countForSteps == 6){
            steps = 1;
            update(QRectF(-40,-50,80,100));
        } else if (countForSteps == 12){
            steps = 0;
            update(QRectF(-40,-50,80,100));
        } else if (countForSteps == 18){
            steps = 2;
            update(QRectF(-40,-50,80,100));
        } else if (countForSteps == 24) {
            steps = 0;
            update(QRectF(-40,-50,80,100));
            countForSteps = 0;
        }
    }
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()<< mapToScene(0, 0)<< mapToScene(-2, -2)<< mapToScene(2, -2));

    foreach (QGraphicsItem *item, foundItems) {
        if (item == this)
            continue;
        if(item == target){
            emit signalCheckGameOver();
        }
    }

    if(this->x() - 10 < -250){
        this->setX(-240);
    }
    if(this->x() + 10 > 250){
        this->setX(240);
    }

    if(this->y() - 10 < -250){
        this->setY(-240);
    }
    if(this->y() + 10 > 250){
        this->setY(240);
    }
}

void Enemy::pause()
{
    if(timer->isActive()){
        timer->stop();
    } else {
        timer->start(15);
    }
}
