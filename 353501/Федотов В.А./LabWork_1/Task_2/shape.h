#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPointF>
#include <QTransform>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QtMath>

class Shape : public QGraphicsObject
{
public:
    Shape();

    //variables
    bool detached = false;
    qreal anglePoly;
    qreal scale = 1;
    qreal rotation = 0;
    qreal lastRotation;

    int numPoints = 5;

    QPointF center;
    QPointF shift;
    QPointF shiftDetached;

    qreal centerX = 0;
    qreal centerY = 0;
    qreal radius1 = 100;
    qreal radius2 = 50;

    qreal shiftX = 0;
    qreal shiftY = 0;
    qreal lastShiftX;
    qreal lastShiftY;

    qreal side1, side2, side3;

    //arrays
    QVector<QPointF> points;
    QVector<qreal> pointsX;
    QVector<qreal> pointsY;

    //functions
    virtual void upScale();
    virtual void downScale();

    virtual void rotateLeft();
    virtual void rotateRight();

    virtual void changeX(qreal value);
    virtual void changeY(qreal value);

    virtual void changeSide1(qreal value);
    virtual void changeSide2(qreal value);
    virtual void changeSide3(qreal value);

    virtual void changeAngle(qreal value);

    virtual void changePoints(int value);
    virtual void changeRadius1(qreal value);
    virtual void changeRadius2(qreal value);

    virtual void setDetached(bool isChecked);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    virtual void calculatePoints();
    virtual void setCenterOfMass();

    virtual qreal area();
    virtual qreal perimeter();

    virtual void clear();

    QRectF boundingRect() const override;

};

#endif // SHAPE_H
