#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

const int DEF_RAD=10000;

class Circle : public Figure
{
    Q_OBJECT
public:
    double radius = DEF_RAD;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void updateSquare() override;
    void updatePerimetr() override;
    void updateRadius();
    void updateCentre() override;
    void updateInfo() override;
};

#endif // CIRCLE_H
