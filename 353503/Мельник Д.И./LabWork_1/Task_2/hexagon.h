#ifndef HEXAGON_H
#define HEXAGON_H
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Hexagon : public Figure
{
    Q_OBJECT
public:
    explicit Hexagon(QPointF point, QObject *parent = 0);
    ~Hexagon();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};

#endif // HEXAGON_H
