#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure
{
    Q_OBJECT

public:
    explicit Triangle(QWidget *parent = nullptr);
    Triangle(const QVector<QPoint>&, QPair<short, short>, QColor = Qt::gray, QWidget* = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getCenter();
    qreal getSquare();
    qreal getPerimeter();

    QPair<int, int> getParameter();
    void setParameter(QPair<int, int>);
};

#endif // TRIANGLE_H
