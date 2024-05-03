#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure
{
public:
    Triangle();
    int a = 0;
    float findArea() override;
    float findPerimeter() override;
    QPoint getCenter() override;
    void setA(int);
    int getA();
    void setPoints(const QVector<QPointF>& points);
    bool isDrawing = false;

    void rotateRight();
    void rotateLeft();

    void setRotationCenter();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
private:
    QVector<QPointF> points;
};

#endif // TRIANGLE_H
