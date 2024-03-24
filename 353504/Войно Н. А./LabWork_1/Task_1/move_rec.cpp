#include "move_rec.h"

Move_rec::Move_rec(QWidget *parent): QWidget(parent){
    setFixedSize(200,450);
}

void Move_rec::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QRect Rectungle(0, 0, 200, 450);
    painter.fillRect(Rectungle, Qt::darkGreen);
}

void Move_rec::left(int distance, int duration){
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(duration);
    animation->setEndValue(QPointF(x() - distance, y()));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Move_rec::right(int distance, int duration){
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(duration);
    animation->setEndValue(QPointF(x() + distance, y()));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
