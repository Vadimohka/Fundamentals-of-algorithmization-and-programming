#ifndef FIGURE_H
#define FIGURE_H

#include <QVector>
#include <QPolygon>
#include <QPainter>
#include <QPoint>
#include <QPointF>
#include <QMouseEvent>
#include <cmath>
#include <algorithm>
#include <QObject>
#include <QDebug>


class Figure : public QObject
{

protected:

    QPointF center;
    QPointF nPoint;

    double s;
    double p;

public:
    Figure();
    virtual void draw(QPainter *pntr);

    virtual void move(QPointF nPoint);
    virtual void setSize(QPointF nPoint);
    virtual void rotateR();
    virtual void rotateL();
    virtual void upScale();
    virtual void downScale();
    virtual double getS();
    virtual double getP();
    virtual int getId();
    double getCordCenterX();
    double getCordCenterY();
    QPointF getCenter();
    virtual QVector<QPointF> getPointsVector();
    virtual void setCenterEdit(QPointF newPoint, int pointN);
    virtual QPointF getRadSize();




};

#endif // FIGURE_H
