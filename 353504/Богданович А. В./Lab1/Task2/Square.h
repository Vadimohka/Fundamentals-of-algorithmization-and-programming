#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

class Square : public Figure
{
public:
    Square();
    int a = 0;
    float findArea() override;
    float findPerimeter() override;
    void setA(int);
    int getA();
    QPoint getCenter() override;
    bool isDrawing = false;
    void setPoints(const QVector<QPointF>& points);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    QPointF startPoint;

private:
    QVector<QPointF> points;
};

#endif // SQUARE_H
