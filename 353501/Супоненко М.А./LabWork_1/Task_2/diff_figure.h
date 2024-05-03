#pragma once

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class diff_figure : public Figure
{
    Q_OBJECT

public:
    explicit diff_figure(QPointF point, QObject *parent = 0);
    ~diff_figure();
    double Ploshad();
    double Perimeter();

private:
    // Для другой фигуры реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
