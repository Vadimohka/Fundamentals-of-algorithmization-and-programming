#ifndef STAR_H
#define STAR_H
#include "figures.h"
#include <QVector>

class Star : public Figure
{
private:
    int number = 0;
    qreal Angle = 0.0;

    QVector<QPointF> points;

    qreal radius1 = 50.0;
    qreal radius2 = 80.0;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    qreal squareOfFigure() override;
    qreal perimetrOfFigure() override;

    void resize(qreal changeSize) override;

public:
    Star(int numberOfStar, bool isPolygon = false);
    ~Star() = default;
};

#endif // STAR_H
