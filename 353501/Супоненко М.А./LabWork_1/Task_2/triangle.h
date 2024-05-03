#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include "figure.h"

class Triangle : public Figure
{
    Q_OBJECT

public:
    explicit Triangle(QPointF point, QObject *parent = 0);
    ~Triangle();
    double Ploshad();
    double Perimeter();
    void paintPoint();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


