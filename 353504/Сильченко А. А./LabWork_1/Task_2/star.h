#ifndef STAR_H
#define STAR_H

#include "figure.h"

class Star : public Figure{
public:
    int size = 5;
    Star(int n, Figure *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void findSquare() override;
    void findPerimetr() override;
};

#endif // STAR_H
