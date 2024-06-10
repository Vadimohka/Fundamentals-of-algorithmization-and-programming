#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"

class Polygon : public Shape
{
public:
    Polygon();
    void setPoints(QVector<QPointF>) override;
    virtual long double square() override{ return 0;};
    virtual long double perimetr() override{return 0;};
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;
private:
    QVector<QPointF> p;
};

#endif // POLYGON_H
