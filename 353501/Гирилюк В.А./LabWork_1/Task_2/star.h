#ifndef STAR_H
#define STAR_H

#include "shape.h"

class Star: public Shape
{
public:
    QTimer *starTimer;
    QPointF *drawPoints = nullptr;
    int count_points = 5;
    double radA = 100, radB = 50, current_radA = 100, current_radB = 50;
    Star(QGraphicsItem *parent = nullptr);
    ~Star();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void Resize();
    QRectF boundingRect() const;
};

#endif // STAR_H
