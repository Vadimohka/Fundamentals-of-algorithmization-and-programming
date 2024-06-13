#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure
{
    Q_OBJECT
public:
    Rectangle();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    double updateS() override;
    double updateP() override;
    void updateR() override;
    void updateCentre();
    void ystanVershin();

private:
    QVector<QPointF> vershin;
    double x, y, height, width;
};

#endif // RECTANGLE_H
