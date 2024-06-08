#include "turtle.h"
#include <QPainter>

Turtle::Turtle(QRectF platformRect, int direction,QGraphicsItem *parent)
    : QGraphicsItem(parent)
      ,mCurrentFrame6(),mPlatform(platformRect), mDirection(direction)

{
    setFlag(ItemClipsToShape);
    mPixmap6 = QPixmap(":images/turtle.png");

}

void Turtle::nextFrame6(){

    mCurrentFrame6 += 72;
    if (mCurrentFrame6 >= 1420 ) {
        mCurrentFrame6 = 0;
    }
    if(this->pos().x() < mPlatform.x() || this->pos().x() > mPlatform.x()+ mPlatform.width()) {
        mDirection = -mDirection;
        setTransform(QTransform(-mDirection, 0, 0, 1, boundingRect().width(), 0));
    }
    setPos(this->pos().x() + (mDirection*7), this->pos().y());

}

QRectF Turtle::boundingRect() const {
    return QRectF(0,0,68,60);

}

void Turtle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, mPixmap6, mCurrentFrame6, 0,68, 60);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);

}

int Turtle::type() const {
    return Type;
}

