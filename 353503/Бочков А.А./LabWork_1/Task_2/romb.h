#ifndef ROMB_H
#define ROMB_H

#include <shape.h>

class romb : public shape
{
    Q_OBJECT
public:
    explicit romb(QPointF point, QObject *parent = 0);
private:
    double getSquare();
    double getPerim();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ROMB_H
