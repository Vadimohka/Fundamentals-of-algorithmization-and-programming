#include "movingrectangle.h"

MovingRectangle::MovingRectangle()
{
    IsAnimating = false;
    GoingAnimation = new QTimer;
}

MovingRectangle::~MovingRectangle()
{
    delete GoingAnimation;
}

MovingRectangle::MovingRectangle(QPointF initPos, QSizeF initSize)
{
    setRect(QRectF(initPos, initSize));
    IsAnimating = false;
    GoingAnimation = new QTimer;
}

void MovingRectangle::setRect(QRectF NewRect)
{
    rect = NewRect;
}

QRectF MovingRectangle::getRect()
{
    return rect;
}

void MovingRectangle::moveLittle(QPointF shift)
{
    rect.moveTo(rect.topLeft() + shift);
    actualShift += shift;
}

void MovingRectangle::move(QPointF shift, qreal duration)
{
    if (duration <= 0) return;
    QTimer* animationTimer = new QTimer;
    QTimer* endTimer= new QTimer;
    QPointF speed = shift / (duration / 20);
    actualShift = QPointF(0, 0);
    QObject::connect(animationTimer, &QTimer::timeout, [=](){
        moveLittle(speed);
    });
    QObject::connect(endTimer, &QTimer::timeout, [=]() {
        animationTimer->stop();
        endTimer->stop();
        moveLittle(shift - actualShift);
        delete animationTimer;
        delete endTimer;
    });
    animationTimer->start(20);
    endTimer->start(duration - 20);
}

bool MovingRectangle::CheckIsAnimating(qreal duration) {
    if (IsAnimating) return true;
    if (duration == 0) return IsAnimating;
    IsAnimating = true;
    QObject::connect(GoingAnimation, &QTimer::timeout, [=](){
        IsAnimating = false;
        GoingAnimation->stop();
    });
    GoingAnimation->start(duration + 50);
    return false;
}
