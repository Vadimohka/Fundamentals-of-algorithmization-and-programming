#ifndef ELIPS_H
#define ELIPS_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"


class Elips : public Figure
{
    Q_OBJECT
public:
    explicit Elips(QPointF point, QObject *parent = nullptr);
    QColor myColor = randomColor();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    QVector<QPointF> points;

};

#endif // ELIPS_H
