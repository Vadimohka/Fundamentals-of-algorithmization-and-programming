#ifndef SIXPOINTEDSTAR_H
#define SIXPOINTEDSTAR_H

#include <QGraphicsItem>
#include <QObject>

#include "figure.h"

class SixPointedStar : public Figure
{
    Q_OBJECT

public:
    explicit SixPointedStar(QPointF point, QObject *parent = nullptr);

private:
    const int16_t points = 12;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SIXPOINTEDSTAR_H
