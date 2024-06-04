#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <cmath>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QtWidgets>

class Figure: public QGraphicsScene, public  QGraphicsItem
{
public:
    Figure();
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
    QVector<QPoint> points;

    void move();
    void mousePressing(QMouseEvent *);
    void mouseMovePressing(QMouseEvent *);
    void mouseMoving(QMouseEvent *);
    void mouseMoveMoving(QMouseEvent *);

    QPoint center;
    QPoint mouseMovePress;
    QPoint mouseMoveNow;
    QPoint mousePress;
    QPoint mouseNow;
private:
    bool Flag;
    float scale = 1.0;
    float angle = 0;
    QPointF previousPoint;
protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    Figure *currentItem;
};

#endif // SHAPE_H
