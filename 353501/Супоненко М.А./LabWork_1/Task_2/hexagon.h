#pragma once

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Hexagon : public Figure
{
    Q_OBJECT

public:
    explicit Hexagon(QPointF point, QObject *parent = 0);
    ~Hexagon();
    double Ploshad();
    double Perimeter();

private:
    // Для Шестиугольника реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

