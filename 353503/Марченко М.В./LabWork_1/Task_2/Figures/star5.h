#ifndef STAR5_H
#define STAR5_H

#include <QObject>
#include <QGraphicsItem>
#include "Figures/figure.h"

class Star5 : public Figure
{
    Q_OBJECT

public:
    explicit Star5(QPointF point, QObject *parent = 0);
    ~Star5();
    long double GetArea();
    long double GetPerimeter();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STAR5_H
