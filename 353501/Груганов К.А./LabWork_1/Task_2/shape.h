#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include<QMouseEvent>
#include <QMainWindow>
#include<QGraphicsView>
#include <QComboBox>
#include <QPainterPath>
#include <QColor>
class Shape
{
public:
    Shape();
    ~Shape();

    virtual void paint(QPainter *);

    void move();

    QPointF MassCenter();

    void resize();

     void upScale();

    void downScale();

    void rotationMatrix(int newAngle,QPointF anchor);

    void rotateL(QPointF anchor);

    void rotateR(QPointF anchor);

    void updateInfo();

    void Center();

    virtual void mouseMoving(QMouseEvent*e);

    QPointF posMove={0,0};
    QPointF center={600,450};
    QPointF anchor;

    int currAngle=0;
    double area=0;
    double perimetr=0;

    QVector <QPointF> pts;

    int ptsCount;
    double prevScale=1;
    double currScale=1;

    double Area();

    double Perimeter();
};
#endif // SHAPE_H
