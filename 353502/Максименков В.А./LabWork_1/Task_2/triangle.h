#ifndef TRIANGLE_H
#define TRIANGLE_H
//#include <QGraphicsItem>
#include "shape.h"

class Triangle : public Shape
{
private:
    QPointF A = QPointF(0.0, 0.0);
    QPointF B = QPointF(0.0, 0.0);
    QPointF C = QPointF(0.0, 0.0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void resizeShape(QPointF now) override;
    void setDefaultDistanceForTriangle() override;
    qreal squareOfShape() override;
    qreal perimetrOfShape() override;

    void setCenterOfShapeNow(QPointF center) override;
    void setPositionOfTheShape(QPointF pos) override;
    QPointF getScenePosition() override;


public:
    Triangle(QPointF _A, QPointF _B, QPointF _C);
    ~Triangle() = default;
};

#endif // TRIANGLE_H
