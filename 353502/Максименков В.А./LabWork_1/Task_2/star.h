#ifndef STAR_H
#define STAR_H
#include "shape.h"
#include <QVector>

class Star : public Shape
{
private:
    int number = 0;
    qreal angle = 0.0;

    QVector<QPointF> points;

    qreal radius1 = 50.0;
    qreal radius2 = 80.0;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void resizeShape(QPointF now) override;
    qreal squareOfShape() override;
    qreal perimetrOfShape() override;

    void reinterpret(qreal parametr1, qreal parametr2) override;

public:
    Star(int numberOfStar, bool isPolygon = false);
    ~Star() = default;
};

#endif // STAR_H
