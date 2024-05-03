#ifndef SQUARE_H
#define SQUARE_H


#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Square : public Figure
{
    Q_OBJECT

public:
    explicit Square(QPointF point, QObject *parent = 0);
    QColor myColor = randomColor();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QVector<QPointF> points;
};

#endif // SQUARE_H
