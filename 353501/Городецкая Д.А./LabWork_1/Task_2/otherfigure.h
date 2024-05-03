#pragma once

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class otherfigure : public Figure
{
    Q_OBJECT

public:
    explicit otherfigure(QPointF point, QObject *parent = 0);
    ~otherfigure();
    double Ploshad();
    double Perimeter();

private:
    // Для другой фигуры реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};