#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"

class Hexagon : public Shape
{
public:
    Hexagon();
    void setPoints(QVector<QPointF>) override;
    long double square() override;
    long double perimetr() override;
    qreal getSpecificParam_1() override;
    void setSpecificParam_1(qreal) override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;
private:
    long double a = 0;
    QRectF rect;
    QPointF Topleft;
};

#endif // HEXAGON_H
