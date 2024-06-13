#ifndef BLIN_H
#define BLIN_H

#include <QtWidgets>

enum { WIDTH_BLIN = 175, HIGH_BLIN = 180 };

class Blin : QGraphicsItem
{
private:
    double high = HIGH_BLIN;
    double width = WIDTH_BLIN;
    int n = 0;
    QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

public:
    Blin();
    double myScale;
    static int num;
};

#endif // BLIN_H
