#pragma once

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Paintt : public Figure
{
    Q_OBJECT

public:
    explicit Paintt(QPointF point, QObject *parent = 0);
    ~Paintt();

private:
    // Для рисовалки реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

