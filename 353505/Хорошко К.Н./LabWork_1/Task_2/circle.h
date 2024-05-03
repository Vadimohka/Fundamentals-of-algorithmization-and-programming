#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"


class Circle : public Figure
{
    Q_OBJECT
public:
    explicit Circle(QPointF point, QObject *parent = nullptr);
    QVector<QPointF> points;
    QColor myColor = randomColor();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
};

#endif // CIRCLE_H
