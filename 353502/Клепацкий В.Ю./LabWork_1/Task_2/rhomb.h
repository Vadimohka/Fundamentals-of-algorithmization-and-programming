#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"

class Rhomb : public Figure
{
    Q_OBJECT
public:
    Rhomb();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    double updateS() override;
    double updateP() override;
    void updateR() override;
    void updateCentre() override;
    void ystanVershin();

private:
    double diagolFirst, diagolSecond;
    QVector<QPointF> vershin;
};

#endif // RHOMB_H
