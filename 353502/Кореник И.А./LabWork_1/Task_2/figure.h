#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include <QPainter>
#include <QTimer>
#include <QPointF>
#include <QtMath>
class Figure : public QWidget
{
    Q_OBJECT
public:
    explicit Figure(QWidget *parent = nullptr);

    QPolygonF pol;

    virtual void setPoints();

    virtual void draw(QPainter*);

    void setInfo();

    virtual void mousePressing(QMouseEvent*);

    virtual void mouseMoving(QMouseEvent*);

    virtual void mousePressingMoveMode(QMouseEvent*);

    virtual void mouseMovingMoveMode(QMouseEvent*);

    float getArea();

    float getPerimetr();

    QPointF getCentre();

    void rotate(float);

    virtual bool isInside(QMouseEvent*);

    virtual void setN(QString);

public slots:

    virtual void rotateRight();
    virtual void rotateLeft();
    virtual void increase();
    virtual void decrease();

protected:
    virtual void calcArea();
    virtual void calcPerimetr();
    virtual void calcCentre();

    virtual void move();



    QPoint mousePress;
    QPoint mouseInMoving;
    QPoint mouseNow;
    QPointF centre;
    float area;
    float perimetr;
    const float angle = -0.01;
    const float resizeConst = 0.01;
    std::vector<QPointF> points;

};

#endif // FIGURE_H
