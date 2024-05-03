#pragma once

#ifndef STAR_H
#define STAR_H
 
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
    explicit Star(QPointF point, QObject *parent = 0);
    ~Star();
 
private:
    // Для Треугольника реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};
 
#endif // STAR_H