#ifndef STAR_H
#define STAR_H

#include <QGraphicsItem>
#include <QObject>

#include "figure.h"

class Star : public Figure
{
    Q_OBJECT

public:
    explicit Star(QPointF point, QObject *parent = nullptr);

private:
    const int16_t points = 10;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // STAR_H
