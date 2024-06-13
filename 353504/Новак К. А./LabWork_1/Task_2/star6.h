#ifndef STAR6_H
#define STAR6_H

#include <shape.h>

class star6 : public shape
{
    Q_OBJECT
public:
    explicit star6(QPointF point, QObject *parent = 0);
    QRectF boundingRect() const override;
private:
    double getSquare();
    double getPerim();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // STAR6_H
