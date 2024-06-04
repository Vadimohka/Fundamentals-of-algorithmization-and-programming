#ifndef RINGS_H
#define RINGS_H

#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Rings : public QGraphicsRectItem, public QObject
{

public:
    Rings(qreal, qreal, qreal, qreal, QGraphicsItem* parent = nullptr);

    void SetHaracteristics(double, double);
    double size;
    double height;

    qreal x;
    qreal y;

    QPointF Pos();
    void Move_up(qreal);
    void Move_right(qreal);

};

#endif // RINGS_H
