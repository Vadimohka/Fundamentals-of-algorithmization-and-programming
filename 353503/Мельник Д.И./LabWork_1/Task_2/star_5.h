#ifndef STAR_5_H
#define STAR_5_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
     * в котором реализован общий для всех фигур функционал
     * */
class Star_5 : public Figure
{
    Q_OBJECT

public:
    explicit Star_5(QPointF point, QObject *parent = 0);
    ~Star_5();

private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};


#endif // STAR_5_H
