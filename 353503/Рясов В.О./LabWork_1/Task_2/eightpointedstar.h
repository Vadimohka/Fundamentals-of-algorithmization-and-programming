#ifndef EIGHTPOINTEDSTAR_H
#define EIGHTPOINTEDSTAR_H

#include <QGraphicsItem>
#include <QObject>

#include "figure.h"

class EightPointedStar : public Figure
{
    Q_OBJECT

public:
    explicit EightPointedStar(QPointF point, QObject *parent = nullptr);

private:
    const int16_t points = 16;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // EIGHTPOINTEDSTAR_H
