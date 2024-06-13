#ifndef EYES_H
#define EYES_H

#include <QObject>
#include "movingellipse.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>

class Eyes : public MovingEllipse
{
    Q_OBJECT

public:
    Eyes(QObject *parent = nullptr);


private:
    QRectF  boundingRect() const {return QRectF(110,125,210,70);}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QTimer *timer;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};


#endif // EYES_H
