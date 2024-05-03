// truck.h
#pragma once
#include "MyRectangle.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QPainterPath>

class Truck :  public myRectangle {
public:
    Truck(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    
    
    void rotateBodywork(QPainterPath& path, qreal angle);

private:
    QRectF cabRect;
    QRectF bodyRect;
    //QPainterPath bodywork;
    QRectF wheel1;
    QRectF wheel2;
};
