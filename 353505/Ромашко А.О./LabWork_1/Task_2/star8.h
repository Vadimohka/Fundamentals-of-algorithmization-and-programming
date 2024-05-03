#ifndef STAR8_H
#define STAR8_H

#include <QObject>
#include <QGraphicsItem>
#include "basicfigure.h"

/* Наследуемся от класса BasicFigure,
     * в котором реализован общий для всех фигур функционал
     * */
class Star8 : public BasicFigure
{
    Q_OBJECT

public:
    explicit Star8(QPointF point, QObject *parent = 0);
    ~Star8();

private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};


#endif // STAR8_H
