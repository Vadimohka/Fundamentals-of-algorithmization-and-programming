#ifndef STAR_6_H
#define STAR_6_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
     * в котором реализован общий для всех фигур функционал
     * */
class Star_6 : public Figure
{
    Q_OBJECT

public:
    explicit Star_6(QPointF point, QObject *parent = 0);
    ~Star_6();

private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};


#endif // STAR_6_H
