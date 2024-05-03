#ifndef SOLDAT_H
#define SOLDAT_H

#include <QGraphicsItem>
#include <rectangle.h>
#include <QPainter>
#include <QTimer>


class Soldat : public Rectangle
{
private:
    int speed;
public:
    Soldat();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    virtual void advance(int phase);
};

#endif // SOLDAT_H
