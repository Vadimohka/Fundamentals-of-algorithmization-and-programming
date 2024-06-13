#ifndef STARSIX_H
#define STARSIX_H

#include "figure.h"

class StarSix : public Figure
{
    Q_OBJECT
public:
    StarSix();
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
    QVector<QPointF> vershin;
    qreal radius1 = 50.0;
    qreal radius2 = 80.0;
    qreal angle = 0.0;
};

#endif // STARSIX_H
