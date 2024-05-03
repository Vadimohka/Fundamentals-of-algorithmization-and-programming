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
    void NewCenterX(int NewCenterx);
    void NewCenterY(int NewCenterY);
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
    void rotate(int ) ;
    QPoint mouseMovePress;
    QPoint mouseMoveNow;
    QPoint mousePress;
    QPoint mouseNow;
    QVector<QPoint> points;
    QPoint center = QPoint(0,0);
    int lastDegree = 0;
    float scale = 1.0;
private:
    bool Flag;
    float angle = 0;
    QPointF previousPoint;
    Shape *item;
    QMouseEvent *mouse;
protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};


#endif // SHAPE_H
