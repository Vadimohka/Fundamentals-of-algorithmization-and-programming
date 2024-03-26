#ifndef FIGURES_H
#define FIGURES_H

#include "cmath"
#include <QtWidgets>

class Figures: public QGraphicsScene, public  QGraphicsItem
{
public:
    Figures();
    bool getItem();
    void setItem(bool flag);
    virtual float area();
    virtual float perimeter();
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
    void mouseMoving(QMouseEvent *);//
    void mouseMoveMoving(QMouseEvent *);//
    void rotate(int ) ;
    QPoint mouseMovePress;
    QPoint mouseMoveNow;
    QPoint mousePress;
    QPoint mouseNow;
    QVector<QPoint> points;
    QPoint center;
    int lastDegree = 0;
private:
    bool Flag;
    float scale = 1.0;
    float angle = 0;
    //QPointF previousPoint;
    Figures *item;
    QMouseEvent *mouse;
protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // FIGURES_H
