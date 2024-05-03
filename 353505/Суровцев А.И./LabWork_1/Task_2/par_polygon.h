#ifndef PAR_POLYGON_H
#define PAR_POLYGON_H

#include <QList>
#include <QPointF>
#include <QtMath>
#include <QTimer>
#include <QPainter>
#include <QDebug>
class par_polygon
{
private:

public:
    par_polygon();
    par_polygon(QVector <QPointF> p);
    void SetPoints(QVector <QPointF> p);
    void find_per();
    void find_square();
    qreal GetPerimeter();
    qreal GetSquare();
    QPointF GetCenter();
    bool Get_animation_is_true();
    void find_center();
    void turn_animation(qreal rotationAngle, qreal delta);
    void resize_animation(qreal new_scale, qreal delta);
    void movement_animation(QPointF p, qreal delta);
    void draw(QPainter *painter);
    void SetNewCenter(QPointF p);
    void moveToNewCenter();
    void SetStartParams();
protected:
    QVector <QPointF> start_points;
    QVector <QPointF> points;
    QPointF center = {0, 0};
    QPointF new_center = {0, 0};
    qreal centerX = 0;
    qreal centerY = 0;
    qreal square = 0;
    qreal perimetr = 0;
    qreal scale = 1;
    bool animation_is_true = false;
};

#endif // PAR_POLYGON_H
