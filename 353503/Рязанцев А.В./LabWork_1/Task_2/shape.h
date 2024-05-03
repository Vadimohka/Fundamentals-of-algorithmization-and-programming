#ifndef SHAPE_H
#define SHAPE_H

#include <QTransform>
#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QEvent>
#include <QMouseEvent>
#include <QtMath>

#include "funcs.h"

class Shape : public QGraphicsItem, public QObject
{
public:
    Shape(QPointF point, QWidget *parent = nullptr);

    QRectF boundingRect() const;

    virtual qreal GetSquare() = 0;
    virtual qreal GetPerimetr() = 0;
    virtual QPointF GetCenter() = 0;

    QPointF GetStarterPoint() const;
    QPointF GetEndPoint() const;
    void SetStarterPoint(QPointF);
    void SetEndPoint(QPointF);

    qreal GetScale() const;
    void SetScale(qreal);

    qreal GetRotation() const;
    void SetRotate(qreal);

    void UpdateInfo_(qreal scale);
protected:

    QPointF center;
    qreal square, perimetr;
    qreal scaled = 1;
    qreal rotated;
    QPointF StarterPoint;
    QPointF EndPoint;
};

#endif // SHAPE_H
