#include "movingrect.h"
#include "QPainter"

MovingRect::MovingRect(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    // Инициализация прямоугольника
    rect_ = QRectF(0, 0, 90, 40);
    is_move = false;
}

QRectF MovingRect::boundingRect() const
{
    return rect_;
}

void MovingRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(rect_);
}

void MovingRect::move()
{
    if (this->x() > 1800) {
        this->setPos(this->x() - 2000, this->y());
    }
    if (is_move) {
        this->setPos(this->x() + 1, this->y());
    }
}

void MovingRect::turnOnMove()
{
    is_move = !is_move;
}






