#ifndef STAR_H
#define STAR_H

#include "figure.h"

class Star : public Figure
{
    public:
    explicit Star(QPointF point);

    int valueNumberStarPeaks() const;
    void setNumberStarPeaks(int value) ;
    private:
    int numberStarPeaks;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
#endif // STAR_H


