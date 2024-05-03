#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"

class Polygon: public Shape
{
public:
    QTimer *polyTimer;
    QPointF *drawPoints = nullptr;
    int count_points = 5;
    double radA = 100, current_radA = 100;
    Polygon(QGraphicsItem *parent = nullptr);
    ~Polygon();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void Resize();
    QRectF boundingRect() const;
};

#endif // POLYGON_H
