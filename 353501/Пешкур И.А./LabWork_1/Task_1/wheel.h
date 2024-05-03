#ifndef WHEEL_H
#define WHEEL_H

#include "circle.h"
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QWidget>

class Wheel : public Circle
{
    Q_OBJECT

public:

    Wheel(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr );
    void paint( QPainter *painter , const QStyleOptionGraphicsItem *option , QWidget *widget ) override;

public slots:

    void rotate( int angle );

signals:
};

#endif // WHEEL_H
