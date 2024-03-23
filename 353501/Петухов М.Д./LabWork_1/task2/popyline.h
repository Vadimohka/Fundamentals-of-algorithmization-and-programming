#ifndef POPYLINE_H
#define POPYLINE_H

#include <figure.h>

class popyline : public Figure
{
public:
    popyline();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
};

#endif // POPYLINE_H
