#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle();
    void setPoints(QVector<QPointF>) override;
    long double square() override;
    long double perimetr() override;

    qreal getSpecificParam_1() override;
    void setSpecificParam_1(qreal) override;

    qreal getSpecificParam_2() override;
    void setSpecificParam_2(qreal) override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;
    QPolygon pol;
private:
    QPointF top;
    QPointF min;
    QPointF max;
};

#endif // TRIANGLE_H
