#ifndef FIGURE_H
#define FIGURE_H

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>
#include <QVector>
#include <QtMath>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int isSetup = 0;
    double radius, perimetr, square, defaultdist;
    QPointF mouseNow, mousePress, centre;
    QVector<QPointF> vershin;

    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)= 0;
    virtual void ystanVershin() = 0;
    virtual double updateS() = 0;
    virtual double updateP() = 0;
    virtual void updateCentre() = 0;
    virtual void updateR() = 0;

signals:
    void isSceneUpdate();
};

#endif // FIGURE_H
