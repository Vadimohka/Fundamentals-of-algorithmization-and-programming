#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus : public Figure
{
    Q_OBJECT

    qreal a, b;

public:
    explicit Rhombus(QWidget *parent = nullptr);
    Rhombus(const QVector<QPoint>&, QPair<short, short>, QColor = Qt::gray, QWidget* = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getCenter();
    qreal getSquare();
    qreal getPerimeter();

    QPair<int, int> getParameter();
    void setParameter(QPair<int, int>);
};

#endif // RHOMBUS_H
