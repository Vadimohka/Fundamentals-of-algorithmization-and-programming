#pragma once

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Rectangle : public Figure
{
    Q_OBJECT

public:
    explicit Rectangle(QPointF point, QObject *parent = 0);
    ~Rectangle();
    double Ploshad();
    double Perimeter();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
