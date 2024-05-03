#include "movingellipse.h"
#include "MyPolygon.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QGraphicsPolygonItem>
#include <QRandomGenerator>
#include <QGraphicsObject>
#include <QPainter>

movingellipse::movingellipse() {
    QRect(0, 0, 500, 500);
    setFlag(QGraphicsItem::ItemIsMovable);
}

void movingellipse::pop() {

    QPropertyAnimation *scaleAnimation = new QPropertyAnimation(this, "scale");
    scaleAnimation->setDuration(500);
    scaleAnimation->setStartValue(1);
    scaleAnimation->setEndValue(2);

    QPropertyAnimation *scaleBackAnimation = new QPropertyAnimation(this, "scale");
    scaleBackAnimation->setDuration(500);
    scaleBackAnimation->setStartValue(2);
    scaleBackAnimation->setEndValue(1);

    QPropertyAnimation *opacityAnimation = new QPropertyAnimation(this, "opacity");
    opacityAnimation->setDuration(500);
    opacityAnimation->setStartValue(1);
    opacityAnimation->setEndValue(0);

    QPropertyAnimation *opacityBackAnimation = new QPropertyAnimation(this, "opacity");
    opacityBackAnimation->setDuration(500);
    opacityBackAnimation->setStartValue(0);
    opacityBackAnimation->setEndValue(1);

    QSequentialAnimationGroup *animationGroup = new QSequentialAnimationGroup;
    animationGroup->addAnimation(scaleAnimation);
    animationGroup->addAnimation(opacityAnimation);
    animationGroup->addAnimation(scaleBackAnimation);
    animationGroup->addAnimation(opacityBackAnimation);

    animationGroup->start(QAbstractAnimation::DeleteWhenStopped);

    for (int i = 0; i < 50; ++i) {
        MyPolygon* polygon = new MyPolygon();
        polygon->setPos(this->pos());
        scene()->addItem(polygon);

        QPropertyAnimation* animation = new QPropertyAnimation(polygon, "pos");
        animation->setDuration(1000);
        animation->setStartValue(this->pos());
        qreal angle = QRandomGenerator::global()->bounded(2 * M_PI);
        qreal distance = 2000;
        QPointF endPos = this->pos() + QPointF(cos(angle) * distance, sin(angle) * distance);
        animation->setEndValue(endPos);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }



}


void movingellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

