#ifndef RHOMB_H
#define RHOMB_H

#include "abstractfigure.h"

class Rhomb : public AbstractFigure
{
    Q_OBJECT;

public:
    Rhomb(int x1 =0 , int y1 = 0, int x2 = 150 , int y2 = 150);
    ~Rhomb();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RHOMB_H
