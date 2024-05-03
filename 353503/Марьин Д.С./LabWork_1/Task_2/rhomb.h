#ifndef RHOMB_H
#define RHOMB_H

#include "shape.h"

class Rhomb : public Shape
{
public:
    Rhomb();
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
private:
    long double width = 0, height = 0 , a = 0;
    QRectF rect;
    QPointF Topleft;
};

#endif // RHOMB_H
