#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPointF>
#include <QGraphicsObject>
#include <QPolygonF>
#include <QGraphicsRotation>
#include <cmath>
#include <QGraphicsScene>

class Figure : public QGraphicsObject, public QGraphicsScene
{

protected:

    Figure();

    //variables
    qreal scale = 1;

    qreal centerX = 0;
    qreal centerY = 0;


    qreal width;
    qreal height;

    int angle = 0;




public:

    double valueC = 200;
    double valueB = 200;
    double valueA = 200;


    qreal disconnectedMoveX;
    qreal disconnectedMoveY;
    QPointF disconnectedMove;
    bool wasCenterDisconnected = false;
    QPointF shiftCenter;

    double moveX = 0;
    double moveY = 0;
    QPointF move;
    QPointF center = QPointF(centerX, centerY);
    QVector<QPointF> points;
    QVector<qreal> pointsX;
    QVector<qreal> pointsY;
    QRectF boundingRect() const;

    virtual void calculatePoints();
    virtual void setPoints();

    //functions
    virtual void upScale();
    virtual void downScale();

    virtual void moveRight();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveUp();

    virtual void rotate_right();
    virtual void rotate_left();

    //стороны треугольника
    virtual void setValueC(double value);
    virtual void setValueA(double value);
    virtual void setValueB(double value);

    //ромб
    virtual void setRhombWidth(double arg1);
    virtual void setRhombHeight(double arg1);;

    //звезда
    virtual void setInnerRadius();
    virtual void setOuterRadius();
    virtual void setInnerRadiusDown();
    virtual void setOuterRadiusDown();
    virtual void setVertices(int vertices);

    //прямоугольник
    virtual void setWidthRectangle(double value);
    virtual void setHeightRectangle(double value);


    double square{};
    double perimeter{};

    //center
    virtual void setCenter();
    virtual double findSquare();
    virtual double findPerimeter();

    virtual void setMoveX(double arg1);
    virtual void setMoveY(double arg1);

    virtual void clear();
};

#endif // SHAPE_H
