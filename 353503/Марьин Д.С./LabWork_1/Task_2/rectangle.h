#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(); 
    void setPoints(QVector<QPointF>) override;
    long double square() override;
    long double perimetr() override;

    qreal getSpecificParam_1() override;
    void setSpecificParam_1(qreal) override;
    qreal getSpecificParam_2() override;
    void setSpecificParam_2(qreal) override;
    QPointF center;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;

private:
    QRectF rect;
    QPointF Topleft;
    long double a = 0;
    long double b = 0;
};

#endif // RECTANGLE_H
