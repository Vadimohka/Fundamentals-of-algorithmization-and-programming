#ifndef LINE_H
#define LINE_H

#include "figure.h"

class Line : public Figure{
public:
    Line(Figure *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void findSquare() override;
    void findPerimetr() override;
};

#endif // LINE_H
