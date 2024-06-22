#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure
{
    Q_OBJECT

public:
    explicit Square(QWidget *parent = nullptr);
    Square(const QVector<QPoint>&, QPair<short, short>, QColor = Qt::gray, QWidget* = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getCenter();
    qreal getSquare();
    qreal getPerimeter();

    QPair<int, int> getParameter();
    void setParameter(QPair<int, int>);

private:
    qreal side;
};

#endif // SQUARE_H
