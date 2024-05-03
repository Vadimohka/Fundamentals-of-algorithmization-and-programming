#ifndef CUSTOM_H
#define CUSTOM_H

#include <QGraphicsItem>
#include <QPainterPath>
#include <QVector>

class Line : public QGraphicsItem
{
public:
    Line();
    QPainterPath path;
    QVector<QPointF> points; // Вектор для хранения всех точек линии

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CUSTOM_H
