#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QtCore/qmath.h>


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
    bool getItem();
    void setItem(bool flag);
    float getScale();
    void getSize();
    virtual float perimeter();
    virtual float centerX();
    virtual float centerY();
    QPointF center;
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

public:
    QPointF startPoint;
    QPointF endPoint;

    QVector<QPointF> points;
    virtual float area();

public:
    QString ChangeLabel();
};

#endif // FIGURE_H
