#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <shape.h>

class triangle : public shape
{
    Q_OBJECT
public:
    explicit triangle(QPointF point, QObject *parent = 0);
private:
    double getSquare();
    double getPerim();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // TRIANGLE_H
