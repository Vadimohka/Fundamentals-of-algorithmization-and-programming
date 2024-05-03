#ifndef STAR_H
#define STAR_H

#include "shape.h"

#include <QPointF>

class Star : public Shape
{
public:
    Star();
    void setPoints(QVector<QPointF> points) override;
    void setStarType(int type);
    long double square() override;
    long double perimetr() override;
    qreal getSpecificParam_1() override;
    void setSpecificParam_1(qreal) override;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;
    double rotation;
private:
    long double radius = 0;
    double small = 0;
    double angle = 0;
    long double S = 0;
    float starType = 5;
    QPointF c;
    QPointF inner;
    QPointF out;
    QRectF rect;
    QPointF Topleft;

};

#endif // STAR_H
