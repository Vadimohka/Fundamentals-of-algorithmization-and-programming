#ifndef HEXAGON_H
#define HEXAGON_H

#include <shape.h>

class hexagon : public shape
{
    Q_OBJECT
public:
    explicit hexagon(QPointF point, QObject *parent = 0);
private:
    double getSquare();
    double getPerim();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // HEXAGON_H
