#ifndef POLYLINE_H
#define POLYLINE_H


#include <QtWidgets>
#include "figures.h"

class polyline : public figures {
public:
    polyline() = default;

    void setPoints(QMouseEvent *) override;

    void draw(QPainter *) override;

    void findSquare() override;

    void findPerimetr() override;

};
#endif // POLYLINE_H
