#ifndef LAB0T2_FIGUREPOLYLINE_H
#define LAB0T2_FIGUREPOLYLINE_H

#include <QtWidgets>
#include "figures.h"

class figurePolyline : public figures {
public:
    figurePolyline() = default;

    void setPoints(QMouseEvent *) override;

    void draw(QPainter *) override;

    void findSquare() override;

    void findPerimeter() override;

};


#endif //LAB0T2_FIGUREPOLYLINE_H
