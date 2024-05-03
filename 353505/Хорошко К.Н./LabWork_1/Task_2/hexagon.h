#ifndef HEXAGON_H
#define HEXAGON_H


#include <QObject>
#include <QGraphicsItem>
#include "figure.h"


class Hexagon : public Figure
{
    Q_OBJECT
public:
    explicit Hexagon(QPointF point, QObject *parent = nullptr);
    QColor myColor = randomColor();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QVector<QPointF> points;

};

#endif // HEXAGON_H
