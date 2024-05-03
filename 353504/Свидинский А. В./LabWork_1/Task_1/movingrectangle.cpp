#include "movingrectangle.h"
#include <QPropertyAnimation>

MovingRectangle::MovingRectangle(QWidget *parent) : QWidget(parent) {}

void MovingRectangle::moveTo(const QPoint &newPosition) {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(1000);
    animation->setStartValue(this->pos());
    animation->setEndValue(newPosition);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
