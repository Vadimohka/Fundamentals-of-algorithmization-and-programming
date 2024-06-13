#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTransform>
#include <QString>

class Figure : public QGraphicsItem, public QObject
{
public:
    Figure();
    ~Figure();
    virtual QRectF boundingRect() const override;
    virtual double area() = 0;
    virtual double perimetr() = 0;
    virtual QPointF centerOfMass() = 0;
    double distance(int x1, int y1, int x2, int y2);
    double areaOfTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
    int xspeed_ = 2;
    
public slots:
    virtual void move();
    virtual void moveBack();
    virtual void rotate();
    virtual void rotateBack();
    virtual void scale();
    virtual void scaleBack();
    
protected:
    int stop_ = 0;
    double scale_ = 1;
    int xCenter_;
    int yCenter_;
    int rotationAngle_ = 0;
    int rotateCenterX = 0;
    int rotateCenterY = 0;
};

#endif // FIGURE_H
