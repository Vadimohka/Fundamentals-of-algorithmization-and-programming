#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QGraphicsItem>
#include <QPainter>
#include "figure.h"

class Triangle : public Figure
{
public:
    Triangle(int x = -60, int y = 60, int width = 120, int height = 120);
    ~Triangle();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    double area() override;
    double perimetr() override;
    QPointF centerOfMass() override;

private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;
    int x3_;
    int y3_;


    // Figure interface
public slots:
    void move() override;
    void moveBack() override;
    void rotate() override;
    void rotateBack() override;
    void scale() override;
    void scaleBack() override;
};

#endif // TRIANGLE_H
