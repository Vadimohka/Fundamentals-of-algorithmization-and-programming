#ifndef SQUARE_H
#define SQUARE_H

#include <figure.h>

class Square : public Figure
{
    Q_OBJECT
public:
    Square();
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
    double storona;
    QVector<QPointF> vershin;
};

#endif // SQUARE_H
