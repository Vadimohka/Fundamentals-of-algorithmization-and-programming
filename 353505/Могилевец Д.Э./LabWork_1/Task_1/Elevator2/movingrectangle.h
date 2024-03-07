#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H

#include <QRectF>
#include <QPointF>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QCoreApplication>

class MovingRectangle
{
public:
    bool CheckIsAnimating(qreal);
    MovingRectangle();
    ~MovingRectangle();
    MovingRectangle(QPointF, QSizeF);
    void setRect(QRectF);
    QRectF getRect();
    void moveLittle(QPointF);
    void move(QPointF, qreal);
private:
    QRectF rect;
    bool IsAnimating;
    QPointF actualShift;
    QTimer* GoingAnimation;
};

#endif // MOVINGRECTANGLE_H
