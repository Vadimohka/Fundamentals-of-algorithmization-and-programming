#ifndef STAR_H
#define STAR_H

#include "figure.h"

class Star : public Figure
{
    Q_OBJECT

public:
    explicit Star(QWidget *parent = nullptr);
    Star(const QVector<QPoint>&, const short, QPair<short, short>, QColor = Qt::gray, QWidget* = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getCenter();
    qreal getSquare();
    qreal getPerimeter();

    QPair<int, int> getParameter();
    void setParameter(QPair<int, int>);

private:
    QVector<QPointF> inner_points;
    QVector<QPointF> all_points;
    short amnt;
    qreal length, minilength;
    qreal perimeter;
};

#endif // STAR_H
