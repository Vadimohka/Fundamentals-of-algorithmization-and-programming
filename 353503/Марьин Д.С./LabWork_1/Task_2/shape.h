#ifndef SHAPE_H
#define SHAPE_H

#include "QtWidgets/qgraphicssceneevent.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsItem>

static const double Pi = 3.14159265358979323846264338327950288419717;

class Shape : public QGraphicsObject
{
public:
    Shape(QObject *parent = nullptr);
    void mousePressing(QPointF);
    void mouseMoving(QPointF);
    QColor getColor();
    void setColor(QColor);
    QBrush getBrush();
    void setBrush(QBrush);
    virtual long double square() = 0;
    virtual long double perimetr() = 0;
    virtual void setPoints(QVector<QPointF> p);
    QPointF get_Center();
    void set_Center(QVector<QPointF> p);
    void set_Scale(qreal);
    qreal get_Scale();
    QPointF center;

    virtual qreal getSpecificParam_1() = 0;
    virtual qreal getSpecificParam_2() {return 0;};
    virtual void setSpecificParam_1(qreal) = 0;
    virtual void setSpecificParam_2(qreal) {};
protected:
    QPointF mouse_Press;
    QPointF mouse_Now;
    QVector<QPointF> temp;
    QPolygon polygon;
    bool is_selected = false;
private:
    QColor color = Qt::black;
    QBrush brush = Qt::NoBrush;
    qreal scale = 1;
};

#endif // SHAPE_H
