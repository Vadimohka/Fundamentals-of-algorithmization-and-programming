#ifndef MRECTANGLE_H
#define MRECTANGLE_H

#include <QGraphicsItem>
#include <QPointF>
#include <QPainter>
#include <QWidget>
#include <QObject>

class Mrectangle:public QGraphicsItem, public QObject
{

private:
    qreal rotationAngle = 0;
public:
    Mrectangle();
    void rotateR();
    void rotateL();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // MRECTANGLE_H
