#ifndef STAR8_H
#define STAR8_H

#include <QObject>
#include <QGraphicsItem>
#include "Figures/figure.h"

class Star8 : public Figure
{
    Q_OBJECT

public:
    explicit Star8(QPointF point, QObject *parent = 0);
    ~Star8();
    long double GetArea();
    long double GetPerimeter();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STAR8_H
