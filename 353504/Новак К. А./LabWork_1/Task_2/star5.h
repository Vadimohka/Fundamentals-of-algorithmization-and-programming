#ifndef STAR5_H
#define STAR5_H

#include <shape.h>

class star5 : public shape
{
    Q_OBJECT
public:
    explicit star5(QPointF point, QObject *parent = 0);
    QRectF boundingRect() const override;
private:
    double getSquare();
    double getPerim();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // STAR5_H
