#ifndef DRAW_H
#define DRAW_H


#include <QObject>
#include <QGraphicsItem>
#include <QPainterPath>
#include "figure.h"


class  Draw : public Figure
{
    Q_OBJECT
public:
    explicit Draw(QPointF point, QObject *parent = nullptr);

    QVector<QPointF> points;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // DRAW_H
