#pragma once

#ifndef POLYGONE_H
#define POLYGONE_H
 
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"
 
/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Polygone : public Figure
{
    Q_OBJECT
 
public:
    explicit Polygone(QPointF point, QObject *parent = 0);
    ~Polygone();
 
private:
    // Для Треугольника реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};
 
#endif // POLYGONE_H