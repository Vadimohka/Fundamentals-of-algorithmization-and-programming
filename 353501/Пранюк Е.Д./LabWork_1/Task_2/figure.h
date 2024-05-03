#ifndef FIGURE_H
#define FIGURE_H


#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <cmath>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRotation>

class Figure : public QGraphicsObject
{
public:
    int k=2;

    void changeK();
    QPoint getCenter();
    QPoint center;
    bool getItem();
    void setItem(bool flag);
    float getScale();
    void getSize();
    virtual float perimeter();
private:
    bool Flag;
    float scale = 1.0;
    float angle = 0;
public:
    int lastDegree=0;
protected:
    Figure();

    QRectF boundingRect() const;
    //Figure *tempFigure;


public:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

   /* enum Figures{
        Rectangle,
        Circle,
        Triangle,
        Rhombus,
        Hexagon,
        Custom,
        Star5,
        Star6,
        Star8
    };*/

public:
    QPointF startPoint;
    QPointF endPoint;

    QVector<QPointF> points;
    virtual float area();

public:
    QString ChangeLabel();
    //void paintEvent(QPaintEvent *event);
   // double perimeter=0;
/*
    ;
    void rotate_right();
    void rotate_left();  */
    //int lastDegree;

    //double findPerimeter();

    //QString changeLabel();
};

#endif // FIGURE_H
