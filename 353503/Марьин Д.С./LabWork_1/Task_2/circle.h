#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QWidget>
#include <QLine>
#include "shape.h"

class Circle : public Shape
{
public:
    Circle();
    void setPoints(QVector<QPointF>) override;
    long double square() override;
    long double perimetr() override;
    qreal getSpecificParam_1() override;
    void setSpecificParam_1(qreal) override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;
private:
    qreal radius = 0;
    QRectF rect;
    QPointF Topleft;
};

#endif // CIRCLE_H
