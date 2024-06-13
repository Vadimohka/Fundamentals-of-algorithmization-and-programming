#ifndef SHESTIYGOL_H
#define SHESTIYGOL_H

#include "figure.h"

class Shestiygol : public Figure
{
    Q_OBJECT
public:
    Shestiygol();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void ystanVershin() override;
    double updateS() override;
    double updateP() override;
    void updateR() override;
    void updateCentre() override;

private:
    double vusota;
};

#endif // SHESTIYGOL_H
