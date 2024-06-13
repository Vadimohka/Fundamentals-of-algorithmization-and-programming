#ifndef DIAMOND_H
#define DIAMOND_H

#include "figure.h"
#include <QPainter>

class diamond : public figure
{
    Q_OBJECT
public:
    diamond();
    ~diamond();
    void initialization();
    int x,y,R,G,B,PenSize;
private:
    QRectF boundingRect() const override;
    QPolygonF rhombus;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // DIAMOND_H
