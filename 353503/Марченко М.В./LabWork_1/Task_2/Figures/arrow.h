#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsItem>
#include "Figures/figure.h"

class Arrow : public Figure
{
    Q_OBJECT

public:
    explicit Arrow(QPointF point, QObject *parent = 0);
    ~Arrow();
    long double GetArea();
    long double GetPerimeter();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ARROW_H
