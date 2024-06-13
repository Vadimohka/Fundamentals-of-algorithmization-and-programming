#ifndef MOUTH_H
#define MOUTH_H

#include <QObject>
#include "movingellipse.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>

class Mouth : public MovingEllipse
{
    Q_OBJECT

public:
    Mouth(QObject *parent = nullptr);


private:
    QRectF  boundingRect() const {return QRectF(135,245,150,100);}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QTimer *timer;
    qreal opacity = 0.9;
    bool ClosedMouth = true;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void MoveEllipse();
};


#endif // MOUTH_H
