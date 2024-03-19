#ifndef LINE_FIGURES_H
#define LINE_FIGURES_H

#include "figures.h"

class line_figures : public figures
{
public:
    float area();
    float perimeter();
    void setPoints(QMouseEvent *me);
    void draw(QPainter *,float scale);
    float scale=1;
    QPoint centerOfWidget;
};

#endif // LINE_FIGURES_H
