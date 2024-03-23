#ifndef POLYLINE_H
#define POLYLINE_H

#include "figure.h"

class polyline : public Figure
{
public:
    polyline();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void addPoint(const QPointF& point);
    void clear() override;
};

#endif // POLYLINE_H
