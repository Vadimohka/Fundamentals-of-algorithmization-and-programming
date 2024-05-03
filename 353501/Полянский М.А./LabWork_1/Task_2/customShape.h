#ifndef CUSTOMSHAPE_H
#define CUSTOMSHAPE_H

#include <QWidget>
#include "shape.h"
class customShape : public Shape
{
    Q_OBJECT
public:
    customShape();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void addPoint(const QPointF& point) override;
};

#endif 