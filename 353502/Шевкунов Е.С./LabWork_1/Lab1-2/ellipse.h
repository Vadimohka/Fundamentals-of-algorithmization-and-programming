#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

class Ellipse : public Figure
{
    Q_OBJECT

public:
    explicit Ellipse(QWidget *parent = nullptr);
    Ellipse(const QVector<QPoint>&, QPair<short, short>, QColor = Qt::gray, QWidget* = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getCenter();
    qreal getSquare();
    qreal getPerimeter();
    qreal a, b;

    QPair<int, int> getParameter();
    void setParameter(QPair<int, int>);
};

#endif // ELLIPSE_H
