#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QGraphicsObject>
#include <QTimer>
#include <QPainterPath>

#include "center.h"

class Shape: public QGraphicsObject

{

public:
    Center *center;
    QTimer *timer;
    double area;
    double perimeter;
    double coordobj_X = 0;
    double coordobj_Y = 0;
    double current_coordCenter_X = 0;
    double current_coordCenter_Y = 0;
    double coordCenter_X = 0;
    double coordCenter_Y = 0;
    double rotate = 0;
    double scale = 1;
    double current_Scale = 1;
    Shape(QGraphicsItem *parent = nullptr);
    ~Shape();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    void Rotate();
    void Move();
    void Move_Center();
    void Scale();
};

#endif // SHAPE_H
