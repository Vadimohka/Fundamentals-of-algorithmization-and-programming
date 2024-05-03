#pragma once

#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
 
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"
 
/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Parallelogram : public Figure
{
    Q_OBJECT
 
public:
    explicit Parallelogram(QPointF point, QObject *parent = 0);
    ~Parallelogram();
 
private:
    // Для Треугольника реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
 
#endif // PARALLELOGRAM_H