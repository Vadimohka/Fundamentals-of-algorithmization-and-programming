#include "rectangle.h"

Rectangle::Rectangle() : QGraphicsObject()
{
    floor = 1;
    timer = new QTimer(this);
    shiftY = 0;

    connect(this, &Rectangle::floorChanged, this, &Rectangle::handleFloorChange);
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(0, shiftY, 100, 250);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::gray);

    painter->fillRect(rect, brush);
}

void Rectangle::setFloor(int floor)
{
    emit floorChanged(floor);
    this->floor = floor;
}

void Rectangle::handleFloorChange(int newFloor)
{
    targetY = - 250 * (newFloor - 1);
    disconnect(timer, &QTimer::timeout, this, &Rectangle::incrementYPosition);
    connect(timer, &QTimer::timeout, this, &Rectangle::incrementYPosition);
    timer->start(1);
}

void Rectangle::incrementYPosition()
{
    if(shiftY < targetY){
        shiftY++;
        update();
    } else if (shiftY > targetY){
        shiftY--;
        update();
    } else {
        disconnect(timer, &QTimer::timeout, this, &Rectangle::incrementYPosition);
        timer->stop();
        emit incrementComplete();
    }
}
