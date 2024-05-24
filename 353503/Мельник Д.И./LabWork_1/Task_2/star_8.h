#ifndef STAR_8_H
#define STAR_8_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
     * в котором реализован общий для всех фигур функционал
     * */
class Star_8 : public Figure
{
    Q_OBJECT

public:
    explicit Star_8(QPointF point, QObject *parent = 0);
    ~Star_8();

private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};


#endif // STAR_8_H
