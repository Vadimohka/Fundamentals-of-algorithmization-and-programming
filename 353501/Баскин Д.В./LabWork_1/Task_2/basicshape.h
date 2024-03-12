#ifndef BASICSHAPE_H
#define BASICSHAPE_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <cmath>
#include <QGraphicsScene>
#include <QtWidgets>

class BasicShape : public QGraphicsItem
{
public:
    BasicShape();
    QPoint center;
    QPoint origin;
    QPoint getCenter();
    QPoint getOrigin();
    float getScale();
    void sizeUp();
    void sizeDown();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void origin_move_up();
    void origin_move_down();
    void origin_move_left();
    void origin_move_right();
    void rotate_left();
    void rotate_right();
    void reset();
    virtual void setRadius(int value);
    virtual void setRadiusA(int value);
    virtual void setRadiusB(int value);
    virtual void setSide(int value);
    virtual void setLength(int value);
    virtual void setWidth(int value);
    virtual void setAngle(int value);
    virtual float getRadius();
    virtual float getRadiusA();
    virtual float getRadiusB();
    virtual float getSide();
    virtual float getLength();
    virtual float getWidth();
    virtual float getAngle();
    virtual float area();
    virtual float perimeter();
    void mousePressing(QMouseEvent *);
    void mouseMoving(QMouseEvent *);
    QVector<QPoint> points;
    virtual void setPoints(QMouseEvent *);
private:
    float radius;
    float radiusA;
    float radiusB;
    float side;
    float length;
    float width;
    float angle;
    bool isSizingUp;
    bool isAnimationActive;
    float rotationAngle = 0;
    float scale = 1;
    BasicShape *figure;
protected:
    QPoint mouseNow;
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // BASICSHAPE_H
