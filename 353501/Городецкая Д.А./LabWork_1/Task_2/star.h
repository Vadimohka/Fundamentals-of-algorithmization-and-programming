#pragma once

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Star : public Figure
{
    Q_OBJECT

public:
    explicit Star(QPointF point, int numberStar, QObject *parent = 0);
    ~Star();
    double Ploshad();
    double Perimeter();

private:
    // Для Звезды реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int num;
};