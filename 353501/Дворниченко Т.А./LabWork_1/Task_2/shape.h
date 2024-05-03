#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <cmath>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QtWidgets>

class Shape: public QGraphicsScene, public  QGraphicsItem
{
public:
    Shape();
    bool getItem();
    void setItem(bool flag);
    virtual float area();
    virtual float perimeter();
    virtual void setPoints(QMouseEvent *me);
    float getScale();
    QPoint getCenter();
    void getSize();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void rotate_right();
    void rotate_left();
    void move();
    void mousePressing(QMouseEvent *);
    void mouseMovePressing(QMouseEvent *);
    void mouseMoving(QMouseEvent *);
    void mouseMoveMoving(QMouseEvent *);
    void rotate(int);
    virtual void updateSizeStorona(double arg1);
    virtual void updateSizeStoronaW(double arg1);
    virtual void updateSizeTriangleC(double arg1);
    virtual void updateSizeTriangleB(double arg1);
    virtual void updateSizeTriangleA(double arg1);
    virtual void updateSizeRadiushaha(double arg1) ;
    QPoint mouseMovePress;
    QPoint mouseMoveNow;
    QPoint mousePress;
    QPoint mouseNow;

    int centerX=0,centerY=0;
    QVector<QPoint> points;
    QPoint center;
    int lastDegree = 0;
private:
    bool Flag;
    float scale = 1.0;
    float angle = 0;
    QPointF previousPoint;
    Shape *item;
    QMouseEvent *mouse;
protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);


};

#endif // SHAPE_H
