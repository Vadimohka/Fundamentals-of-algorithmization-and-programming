#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>

#include "basicfigure.h"

class Square : public BasicFigure
{
    Q_OBJECT
public:
    explicit Square(QPointF point, QObject *parent = 0);
    ~Square();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};

#endif // SQUARE_H
