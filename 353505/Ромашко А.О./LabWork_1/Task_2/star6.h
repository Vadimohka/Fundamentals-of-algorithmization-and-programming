#ifndef STAR6_H
#define STAR6_H

#include <QObject>
#include <QGraphicsItem>
#include "basicfigure.h"

/* Наследуемся от класса BasicFigure,
     * в котором реализован общий для всех фигур функционал
     * */
class Star6 : public BasicFigure
{
    Q_OBJECT

public:
    explicit Star6(QPointF point, QObject *parent = 0);
    ~Star6();

private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};


#endif // STAR6_H
