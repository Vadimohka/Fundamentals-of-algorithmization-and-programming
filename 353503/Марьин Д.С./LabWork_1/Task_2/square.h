#ifndef SQUARE_H
#define SQUARE_H

#include"shape.h"

class Square : public Shape
{
public:
    Square();
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

#endif // SQUARE_H
