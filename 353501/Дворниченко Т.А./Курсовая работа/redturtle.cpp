#include "redturtle.h"
#include <QPainter>

RedTurtle::RedTurtle(const QRectF& platformRect, int direction, QGraphicsItem* parent)
    : QGraphicsItem(parent)
    , mCurrentFrame(0)
    , mPlatform(platformRect)
    , mDirection(direction)
    , mPixmap(":images/redt.png")
{
    setFlag(ItemClipsToShape);
}

void RedTurtle::nextFrame()
{
    mCurrentFrame += 179;
    if (mCurrentFrame >= 3521) {
        mCurrentFrame = 0;
    }
    int newX = pos().x() + (mDirection * 7);
    if (newX < mPlatform.x() || newX > mPlatform.x() + mPlatform.width()) {
        mDirection = -mDirection;
        setTransform(QTransform(-mDirection, 0, 0, 1, boundingRect().width(), 0));
    }
    setPos(newX, pos().y());
}

QRectF RedTurtle::boundingRect() const
{
    static const QRectF rect(0, 0, 130, 146);
    return rect;
}

void RedTurtle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->drawPixmap(0, 0, mPixmap, mCurrentFrame, 0, 130, 146);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

int RedTurtle::type() const
{
    return Type;
}
