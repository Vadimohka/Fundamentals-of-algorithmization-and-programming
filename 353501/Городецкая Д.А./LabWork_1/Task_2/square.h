#pragma once

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Square : public Figure
{
    Q_OBJECT

public:
    explicit Square(QPointF point, QObject *parent = 0);
    ~Square();
    double Ploshad();
    double Perimeter();

private:
    // Для Квадрата реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};