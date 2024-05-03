#pragma once

#ifndef PAINT_H
#define PAINT_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Paint : public Figure
{
    Q_OBJECT

public:
    explicit Paint(QPointF point, QObject *parent = 0);
    ~Paint();

private:
    // Для рисовалки реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PAINT_H