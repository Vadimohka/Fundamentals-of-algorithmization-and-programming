#ifndef STAR5_H
#define STAR5_H

#include <QObject>
#include <QGraphicsItem>

#include "basicfigure.h"

class Star5 : public BasicFigure
{
    Q_OBJECT

public:
    explicit Star5(QPointF point, QObject *parent = 0);
    ~Star5();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};


#endif // STAR_5_H
