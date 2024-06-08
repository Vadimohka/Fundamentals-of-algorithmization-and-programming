#include "goomba.h"
#include <QPainter>

Goomba::Goomba(QRectF platformRect, int direction, QGraphicsItem *parent)
    : QGraphicsItem(parent), mCurrentFrame3(), mPlatform(platformRect), mDirection(direction)
{
    setFlag(ItemClipsToShape);
    mPixmap3 = QPixmap(":images/goombas.png");
}

void Goomba::nextFrame3() {
    mCurrentFrame3 += 54;
    if (mCurrentFrame3 >= 862 ) {
        mCurrentFrame3 = 0;
    }

    if(this->pos().x() < mPlatform.x() || this->pos().x() > mPlatform.x()+ mPlatform.width()) {
        mDirection = -mDirection;
        setTransform(QTransform(-mDirection, 0, 0, 1, boundingRect().width(), 0));
    }
    setPos(this->pos().x() + (mDirection*7), this->pos().y());
}

QRectF Goomba::boundingRect() const {
    return QRectF(0,0,52,50);
}

void Goomba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, mPixmap3, mCurrentFrame3, 0,52, 50);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);

}

int Goomba::type() const {
    return Type;
}


