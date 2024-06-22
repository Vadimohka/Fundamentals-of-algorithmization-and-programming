#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure
{
    Q_OBJECT

    qreal a, b;

public:
    explicit Rectangle(QWidget *parent = nullptr);
    Rectangle(const QVector<QPoint>&, QPair<short, short>, QColor = Qt::gray, QWidget* = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getCenter();
    qreal getSquare();
    qreal getPerimeter();

    QPair<int, int> getParameter();
    void setParameter(QPair<int, int>);
};

#endif // RECTANGLE_H
