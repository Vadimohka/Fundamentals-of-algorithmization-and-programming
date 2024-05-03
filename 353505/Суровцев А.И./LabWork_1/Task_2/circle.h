#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPointF>
#include <QtMath>
#include <QTimer>
#include <QPainter>
#include <QDebug>

class Circle
{
public:
    Circle(qreal r, QPointF c);
    void SetParams(qreal r, QPointF c);
    void SetStartParams();
    void find_per();
    void find_square();
    qreal GetPerimeter();
    qreal GetSquare();
    bool Get_animation_is_true();
    QPointF GetCenter();
    void resize_animation(qreal new_scale, qreal delta);
    void movement_animation(QPointF p, qreal delta);
    void SetNewCenter(QPointF p);
    void moveToNewCenter();
    void draw(QPainter *painter);
    void SetNewCoord(qreal r, QPointF c);
private:
    qreal start_r;
    QPointF start_c;
    qreal radius = 0;
    QPointF center = {0, 0};
    QPointF new_center = {0, 0};
    qreal perimeter = 0;
    qreal square = 0;
    qreal scale = 1;
    bool animation_is_true = false;
};

#endif // CIRCLE_H
