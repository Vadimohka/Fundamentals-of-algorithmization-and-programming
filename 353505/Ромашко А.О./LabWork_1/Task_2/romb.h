#ifndef ROMB_H
#define ROMB_H

#include <QObject>
#include <QGraphicsItem>

#include "basicfigure.h"

class Romb : public BasicFigure
{
    Q_OBJECT

public:
    explicit Romb(QPointF point, QObject *parent = 0);
    ~Romb();

private:
    double area();
    double perimeter();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ROMB_H
