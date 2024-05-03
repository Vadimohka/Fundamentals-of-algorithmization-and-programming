#pragma once

#ifndef RECTANGLE_H
#define RECTANGLE_H
 
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"
 
/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Rectangle : public Figure
{
    Q_OBJECT
 
public:
    explicit Rectangle(QPointF point, QObject *parent = 0);
    ~Rectangle();
 
private:
    // Для Треугольника реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
 
#endif // RECTANGLE_H